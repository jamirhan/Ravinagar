#include "TrapsBuilder.h"
#include "CloneCreator.h"
#include "MineCreator.h"
#include "GraphCatcherCreator.h"

TrapsBuilder::TrapsBuilder() = default;

Trap* TrapsBuilder::generate(TrapFactory* trap_factory, const Point& coords, Player* owner) {
    return trap_factory->Create(coords, owner);
}

Trap* TrapsBuilder::generate(std::string type, const Point& coords, Player *owner) {
    if (type == "Clone") {
        return generate(new CloneCreator(), coords, owner);
    } else if (type == "GraphCatcher") {
        return generate(new GraphCatcherCreator(), coords, owner);
    } else if (type == "Mine") {
        return generate(new MineCreator(), coords, owner);
    } else {
        //TODO
    }
}
