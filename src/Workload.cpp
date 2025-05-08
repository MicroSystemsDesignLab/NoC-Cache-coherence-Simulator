#include "Workload.h"
Workload::Workload(uint32_t nodes, uint64_t reqs, double p)
    : gen(std::random_device{}()), dist(p) {}
bool Workload::isRemote(uint64_t idx){
    return dist(gen);
}
