#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <cstdint>
#include <unordered_map>
#include <set>

enum CoheState { I, S, E, M };

struct DirEntry {
    CoheState state;
    std::set<uint32_t> sharers;
};

class Directory {
public:
    Directory(uint32_t nodes);
    void access(uint32_t req, uint32_t addr, bool write);
    uint64_t metadata_bytes() const;
    uint64_t get_invalidations() const;
private:
    std::unordered_map<uint32_t,DirEntry> table;
    uint32_t num_nodes;
    uint64_t inv_count = 0;
};

#endif // PROTOCOL_H
