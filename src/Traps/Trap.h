#pragma once

#include "../Graph.h"
#include "Commutator.h"
#include "Unit.h"

class Trap {
    Point coord;
    Player* owner;
public:
    const Point& GetCoord() const;

    Player* GetOwner() const;

protected:
    Trap(Point coord, Player* owner);

public:
    virtual bool Check(Graph* graph);

    virtual bool Check(Unit* unit);

    std::string CoordTrapFormat();

    virtual ~Trap();
};

class Clone : public Trap {
public:
    Clone(Point coords, Player* owner);

};

class GraphCatcher : public Trap {
public:
    GraphCatcher(Point coords, Player* owner);

    bool Check(Graph*) override;
};

class Mine : public Trap {
public:
    Mine(Point coords, Player* owner);

    bool Check(Unit*) override;
};