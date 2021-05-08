#pragma once

#include "../Graph.h"
#include "Traps/Trap.h"
#include "Commutator.h"
#include "Message.h"

class Trap;

class Unit {
protected:
    Graph* location;
public:
    explicit Unit(Graph*);

    Graph* GetGraph();

    virtual bool Check(Trap*) = 0;
};

class Spy : public virtual Unit {
public:
    explicit Spy(Graph*);

    bool Check(Trap*) override;
};

class CCTV : public virtual Unit {
public:
    explicit CCTV(Graph*);

    bool Check(Trap*) override;
};

class Farmer : public virtual Unit {
public:
    explicit Farmer(Graph*);

    bool Check(Trap*) override;
};

class BestFriend : public virtual Unit {
public:
    explicit BestFriend(Graph*);

    bool Check(Trap*) override;
};
