#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <functional>

using Cycle = uint64_t;

// Event representation
struct Event {
    Cycle time;
    std::function<void()> action;
    bool operator>(Event const &e) const {
        return time > e.time;
    }
};

#endif // EVENT_H
