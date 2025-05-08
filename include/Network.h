#ifndef NETWORK_H
#define NETWORK_H

#include "EventQueue.h"
#include "Router.h"
#include "Protocol.h"
#include "Workload.h"
#include <vector>

class Network {
public:
    Network(int dim, uint64_t req, double p);
    void simulate();
private:
    int dim;
    uint32_t nodes;
    uint64_t requests;
    double p_remote;
    EventQueue eq;
    std::vector<Router*> routers;
    Directory dir;
    Workload wl;
    uint64_t msg_count=0;
};

#endif // NETWORK_H
