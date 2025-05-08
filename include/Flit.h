#ifndef FLIT_H
#define FLIT_H

#include <cstdint>

enum FlitType { HEAD, BODY, TAIL };

struct Flit {
    uint32_t src, dst;
    FlitType type;
    uint64_t pkt_id;
    uint32_t address; // memory line address for coherence
};

#endif // FLIT_H
