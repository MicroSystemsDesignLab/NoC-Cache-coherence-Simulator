#include "Protocol.h"

Directory::Directory(uint32_t n) : num_nodes(n) {}

void Directory::access(uint32_t req, uint32_t addr, bool write){
    auto &e = table[addr];
    if(e.sharers.empty()){
        e.sharers.insert(req);
        e.state = write ? M : E;
    } else if(write){
        for(auto s: e.sharers){
            if(s!=req) inv_count++;
        }
        e.sharers.clear();
        e.sharers.insert(req);
        e.state = M;
    } else {
        e.sharers.insert(req);
        e.state = S;
    }
}

uint64_t Directory::metadata_bytes() const {
    return table.size() * sizeof(DirEntry);
}

uint64_t Directory::get_invalidations() const {
    return inv_count;
}
