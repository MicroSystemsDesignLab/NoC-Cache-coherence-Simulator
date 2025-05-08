#include "EventQueue.h"

void EventQueue::push(const Event &e) {
    std::lock_guard<std::mutex> lock(mtx_);
    pq_.push(e);
}

bool EventQueue::empty() const {
    return pq_.empty();
}

Event EventQueue::pop() {
    std::lock_guard<std::mutex> lock(mtx_);
    Event e = pq_.top();
    pq_.pop();
    return e;
}
