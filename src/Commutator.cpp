#include "Commutator.h"

bool Buy(std::string fail_msg, std::string request, Player* player) {
    if (Config::kRequestCosts.count(request) == 0) {
        Commutator::Receive(new PrintMsg("Неверный запрос!", player));
        return false;
    }
    int cost = Config::kRequestCosts[request];
    if (player->GetPoints() < cost) {
        Commutator::Receive(new PrintMsg(fail_msg, player));
        player->UpdateCoins(-cost);
        return false;
    }
    return true;
}

void Commutator::Receive(Message* message) {
    if (dynamic_cast<EnvMsg*>(message)) {
        auto* msg = dynamic_cast<EnvMsg*>(message);
        GameStat::GetInstance()->Set(msg->env);
    } else if (dynamic_cast<CreateGraph*>(message)) {
        auto* msg = dynamic_cast<CreateGraph*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Graph* new_graph;
        new_graph = new Graph(msg->polynom, cur_player);
        if (new_graph->Distance(cur_player->GetCoord()) > Config::kEps) {
            Receive(new PrintMsg("Ваша позиция должна принадлежать графику функции!", cur_player));
            return;
        }
        if (!Buy("У вас не хвает монет для создания графа", msg->request, cur_player)) {
            return;
        }
        int caught = GameStat::GetInstance()->GetCoins()->Harvest(new_graph);
        cur_player->UpdateCoins(caught);
        GameStat::GetInstance()->GetTraps()->Check(new_graph);
        GameStat::GetInstance()->GetGraphs()->AddGraph(new_graph);
    } else if (dynamic_cast<CreateCoins*> (message)) {
        CoinsBuilder* cb = new CoinsBuilder();
        Config* config = Config::GetInstance();
        cb->SetAntiCoin(config->kAmountCreatedAntiCoins);
        cb->SetClassicCoin(config->kAmountCreatedClassicCoins);
        cb->SetSuperCoin(config->kAmountCreatedSuperCoins);
        GameStat::GetInstance()->GetCoins()->Append(cb->GetResult());
    } else if (dynamic_cast<CreateTrap*> (message)) {
        CreateTrap* msg = dynamic_cast<CreateTrap*>(message);
        TrapsBuilder* tb = new TrapsBuilder();
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        if (!Buy("У вас не хватает монет для создания ловушки " + msg->type, msg->request, cur_player)) {
            return;
        }
        Trap* new_trap = tb->Generate(msg->type, msg->coord, cur_player);
        GameStat::GetInstance()->GetTraps()->AddTrap(new_trap);
        GameStat::GetInstance()->GetUnits()->Check(new_trap); // TODO?
    } else if (dynamic_cast<CreateUnit*>(message)) {
        auto* msg = dynamic_cast<CreateUnit*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Graph* required = GameStat::GetInstance()->GetGraphs()->GetPlayerGraphNum(cur_player, msg->graph_num);
        if (required == nullptr) {
            Receive(new PrintMsg("Графа с таким номером не существует", cur_player));
            return;
        }
        Unit* new_unit = nullptr;
        int cost;
        if (msg->unit_name == "Spy") {
            new_unit = new Spy(required);
        } else if (msg->unit_name == "BestFriend") {
            new_unit = new BestFriend(required);
        } else if (msg->unit_name == "Farmer") {
            new_unit = new Farmer(required);
        } else if (msg->unit_name == "CCTV") {
            new_unit = new CCTV(required);
        } else {
            Receive(new PrintMsg("Сущности такого типа не существует!", cur_player));
            return;
        }
        if (!Buy("У вас не хвает монет для создания " + msg->unit_name, msg->request, cur_player)) {
            return;
        }
        cur_player->UpdateCoins(-cost);
        GameStat::GetInstance()->GetUnits()->AddUnit(new_unit);
        GameStat::GetInstance()->GetTraps()->Check(new_unit);
        if (GameStat::GetInstance()->GetUnits()->HasLastUnit(new_unit)) {
            GameStat::GetInstance()->GetTraps()->Search(new_unit);
        }
    } else if (dynamic_cast<ExitIntoSpaceMsg*>(message)) {
        auto* msg = dynamic_cast<ExitIntoSpaceMsg*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Player* enemy = GameStat::GetInstance()->GetEnemy(cur_player);
        if (enemy->GetCoord().CoordPointFormat() == msg->coord.CoordPointFormat()) { // TODO
            Receive(new PrintMsg("Поздравляем, вы выиграли!", cur_player));
            Receive(new PrintMsg("Вы проиграли!", enemy));
            Receive(new EndMsg());
        }
    } else if (dynamic_cast<CaptureMsg*>(message)) {
        auto* msg = dynamic_cast<CaptureMsg*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Graph* captured_graph;
        captured_graph = new Graph(msg->polynom, cur_player);
        if (!Buy("У вас не хвает монет для захвата графа", msg->request, cur_player)) {
            return;
        }
        if (GameStat::GetInstance()->GetGraphs()->Capture(captured_graph)) {
            Receive(new PrintMsg("Вы успешно захватили граф", cur_player));
        }
    } else if (dynamic_cast<DestroyCapturedGraphMsg*>(message)) {
        auto* msg = dynamic_cast<DestroyCapturedGraphMsg*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Player* enemy = GameStat::GetInstance()->GetEnemy(cur_player);
        Graph* required = GameStat::GetInstance()->GetGraphs()->GetCapturedGraphNum(cur_player, msg->captured_graph_num);
        if (required == nullptr) {
            Receive(new PrintMsg("Захваченного графа с таким номером не существует", cur_player));
            return;
        }
        if (!Buy("У вас не хвает монет для уничтожения графа", msg->request, cur_player)) {
            return;
        }
        Receive(new PrintMsg("Вы уничтожили захваченный граф", cur_player));
        Receive(new PrintMsg("Ваш граф " + required->FormulaFormat() + " был уничножен", enemy));
        GameStat::GetInstance()->GetGraphs()->RemoveGraph(required);
    } else if (dynamic_cast<DestroyOwnGraphMsg*>(message)) {
        auto* msg = dynamic_cast<DestroyOwnGraphMsg*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Graph* required = GameStat::GetInstance()->GetGraphs()->GetPlayerGraphNum(cur_player, msg->graph_num);
        if (required == nullptr) {
            Receive(new PrintMsg("Графа с таким номером не существует", cur_player));
            return;
        }
        if (!Buy("У вас не хвает монет для уничтожения графа", msg->request, cur_player)) {
            return;
        }
        Receive(new PrintMsg("Вы уничножили свой граф " + required->FormulaFormat(), cur_player));
        GameStat::GetInstance()->GetGraphs()->RemoveGraph(required);
    } else if (dynamic_cast<SayHelloMsg*>(message)) {
        auto* msg = dynamic_cast<SayHelloMsg*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Player* enemy = GameStat::GetInstance()->GetEnemy(cur_player);
        Graph* required = GameStat::GetInstance()->GetGraphs()->GetCapturedGraphNum(cur_player, msg->captured_graph_num);
        if (required == nullptr) {
            Receive(new PrintMsg("Графа с таким номером не существует", cur_player));
            return;
        }
        if (!Buy("У вас не хватает монет", msg->request, cur_player)) {
            return;
        }
        Receive(new PrintMsg("Враг сообщил, что захватил ваш граф " + required->FormulaFormat(), enemy));
    } else if (dynamic_cast<MoveMsg*>(message)) {
        auto* msg = dynamic_cast<MoveMsg*>(message);
        Player* cur_player = GameStat::GetInstance()->GetPlayer(msg->player_id);
        Graph* required = GameStat::GetInstance()->GetGraphs()->GetPlayerGraphNum(cur_player, msg->graph_num);
        if (required == nullptr) {
            Receive(new PrintMsg("Графа с таким номером не существует", cur_player));
            return;
        }
        if (cur_player->IsMoved()) {
            Receive(new PrintMsg("Вы уже перемещались", cur_player));
            return;
        }
        if (!Buy("У вас не хватает монет для перемещения", msg->request, cur_player)) {
            return;
        }
        cur_player->Move();
        std::vector<Point> affected_points = required->GetAffectedPoints();
        Point new_coord = affected_points[rand() % affected_points.size()];
        cur_player->Move(new_coord);
    }
    else if (dynamic_cast<PrintMsg*>(message)){
        auto* msg = dynamic_cast<PrintMsg*>(message);
        Game::GetInstance()->write(*msg);
    }
}


Commutator::Commutator() = default;

Commutator* Commutator::GetInstance() {
    if (!obj)
        obj = new Commutator();
    return obj;
}
