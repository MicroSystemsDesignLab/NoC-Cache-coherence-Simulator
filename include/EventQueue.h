#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "Event.h"
#include <queue>
#include <mutex>

class EventQueue {
public:
    void push(const Event &e);
    bool empty() const;
    Event pop();

private:
    std::priority_queue<Event, std::vector<Event>, std::greater<>> pq_;
    std::mutex mtx_;
};

#endif // EVENTQUEUE_H
