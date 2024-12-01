#ifndef N_SHOT_TIMER_H
#define N_SHOT_TIMER_H

#include <vector>
#include <memory>

#include "pollers/poller.hpp"
#include "timers/timer.hpp"

class NShotTimer : public Timer {
/*
	Fire N times, where N>0, with millisecond sleep between calls
*/
public:
	NShotTimer(const unsigned int &nTimes, const unsigned int &sleepMilliseconds) 
		: nTimes_(nTimes),  sleepMilliseconds_(sleepMilliseconds)
	{};
	void registerPoller(std::unique_ptr<Poller> poller) override;
    void start() override;
	void stop() override;
private:
	std::vector<std::unique_ptr<Poller>> pollers_;
	unsigned int nTimes_;
	unsigned int sleepMilliseconds_;
};

#endif
