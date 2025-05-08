#ifndef PACKET_H
#define PACKET_H

#include "Flit.h"
#include <vector>

struct Packet {
    uint32_t src, dst;
    uint64_t id;
    uint32_t address;
    bool write;
    std::vector<Flit> flits;
    Packet(uint32_t s, uint32_t d, uint64_t i, uint32_t addr, bool w, uint32_t flit_size = 1) :
        src(s), dst(d), id(i), address(addr), write(w) {
        // HEAD + BODY* + TAIL
        flits.push_back({s,d,HEAD,i,addr});
        for(uint32_t k=0;k<flit_size;k++)
            flits.push_back({s,d,BODY,i,addr});
        flits.push_back({s,d,TAIL,i,addr});
    }
};

#endif // PACKET_H
