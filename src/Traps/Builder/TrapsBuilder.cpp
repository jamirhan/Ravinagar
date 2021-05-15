#include "TrapsBuilder.h"
#include "CloneCreator.h"
#include "MineCreator.h"
#include "GraphCatcherCreator.h"


Trap* TrapsBuilder::Generate(TrapFactory* trap_factory, const Point& coord, Player* owner) {
    return trap_factory->Create(coord, owner);
}

Trap* TrapsBuilder::Generate(std::string type, const Point& coords, Player* owner) {
    if (type == "Clone") {
        return Generate(new CloneCreator(), coords, owner);
    } else if (type == "GraphCatcher") {
        return Generate(new GraphCatcherCreator(), coords, owner);
    } else if (type == "Mine") {
        return Generate(new MineCreator(), coords, owner);
    } else {
        //TODO
    }
    return nullptr;
}
