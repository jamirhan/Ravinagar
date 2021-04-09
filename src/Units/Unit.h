#pragma once
#include "../Graph.h"


class Unit {
protected:
    Graph* location;
public:
    explicit Unit(Graph*);
    Graph* get_graph();
    virtual void check() = 0;
};

class Spy: public virtual Unit {
public:
    explicit Spy(Graph*);
    void check() override;
};

class CCTV: public virtual Unit {
public:
    explicit CCTV(Graph*);
    void check() override;
};

class Farmer: public virtual Unit {
public:
    explicit Farmer(Graph*);
    void check() override;
};

class BestFriend: public virtual Unit {
public:
    explicit BestFriend(Graph*);
    void check() override;
};
