#include "Graph.h"

#include <utility>


Graph::Graph(Poly polynom, Player* p) : polynom(std::move(polynom)) {
    owner = p;
}

bool Graph::IncludesPoint(Point) {
    return false;
}

double Graph::Distance(Point coord) {
    polynomial<int> a = polynomial{0, 1} - polynomial{coord.x};
    polynomial<int> b = polynom.poly - polynomial{coord.y};
    polynomial<double> pr = a * a + b * b;
    polynomial<double> tmp = pr;
    tmp.data().erase(tmp.data().begin());

    // Поиск производной.
    for (int i = 0; i < tmp.degree(); ++i) {
        tmp[i] *= i + 1;
    }

    double eps = 1e-5;
    double l = 0;
    double r = Config::size * Config::size;
    tmp.data() = {-5, 0, 5, 3};
    Eigen::VectorXd v(tmp.data().size());
    std::reverse(tmp.data().begin(), tmp.data().end());
    for (int i = 0; i < tmp.data().size(); ++i) {
        v[i] = tmp.data()[i];
    }
    std::set<double> roots;
    for (int i = 0; i < 300000; i++)
    {
        roots = RootFinder::solvePolynomial(v, l, r, 1e-8);
    }

    double min_dist = Config::size;

    for (auto root : roots) {
        min_dist = std::min(min_dist, pr.evaluate(root));
    }
    return sqrt(min_dist);
}

Player* Graph::GetOwner() {
    return owner;
}

std::string SignStr(int const& x) {
    return x < 0 ? "-" : "+";
}

std::string InnerCoefficient(int const& x) {
    std::string result(" " + SignStr(x) + " ");
    if (abs(x) != 1)
        result += lexical_cast<std::string>(abs(x));
    return result;
}

std::string Graph::FormulaFormat() {
    auto a = polynom.poly;
    std::string result;
    if (a.size() == 0)
        result += lexical_cast<std::string>(0);
    else {
        unsigned i = a.size() - 1;
        if (a[i] < 0)
            result += "-";
        if (abs(a[i]) != 1)
            result += lexical_cast<std::string>(abs(a[i]));

        if (i > 0) {
            result += "x";
            if (i > 1) {
                result += "^" + lexical_cast<std::string>(i);
                i--;
                for (; i != 1; i--)
                    result += InnerCoefficient(a[i]) + "x^" + lexical_cast<std::string>(i);

                result += InnerCoefficient(a[i]) + "x";
            }
            i--;

            result += " " + SignStr(a[i]) + " " + lexical_cast<std::string>(abs(a[i]));
        }
    }
    return result;
}

bool Graph::IsCaptured() {
    return captured;
}

void Graph::Capture() {
    captured = true;
}

std::vector<Point> Graph::GetAffectedPoints() {
    std::vector<Point> res;
    for (int x = 0; x <= Config::size; ++x) {
        for (int y = 0; y <= Config::size; ++y) {
            if (Distance(Point(x, y)) < Config::kEps) {
                res.push_back(Point(x, y));
            }
        }
    }
    return res;
}
