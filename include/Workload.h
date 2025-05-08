#ifndef WORKLOAD_H
#define WORKLOAD_H

#include <random>
#include <cstdint>

class Workload {
public:
    Workload(uint32_t nodes, uint64_t reqs, double p);
    bool isRemote(uint64_t idx);
private:
    std::mt19937_64 gen;
    std::bernoulli_distribution dist;
};

#endif // WORKLOAD_H
