#ifndef TIMER_H
#define TIMER_H

#include <memory>

#include "pollers/poller.hpp"

class Timer {
public:
    virtual ~Timer() = default;
	virtual void registerPoller(std::unique_ptr<Poller> poller) = 0;
    virtual void start() = 0;
	virtual void stop() = 0;
};

#endif
