#ifndef ROUTER_H
#define ROUTER_H

#include "Flit.h"
#include "EventQueue.h"
#include <queue>
#include <array>

struct Router {
    uint32_t id;
    int dim;
    EventQueue *eq;
    std::array<std::queue<Flit>,4> in_q; // N,E,S,W
    std::array<std::queue<Flit>,4> out_q;
    std::array<int,4> credits;
    Router(uint32_t i, int d, EventQueue *q);
    void recv_flit(const Flit &f, Cycle at);
    void schedule_stage(uint32_t port, Cycle when);
    void process_flit(uint32_t port);
};

#endif // ROUTER_H
