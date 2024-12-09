#ifndef N_SHOT_TIMER_H
#define N_SHOT_TIMER_H

#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>


#include "timers/timer.hpp"
#include "actors/actor.hpp"
#include "actors/actor_message_pair.hpp"
#include "messages/message.hpp"


class NShotTimer: public Timer {
/*
	Fire N times, where N>0, with millisecond sleep between calls
*/
public:
	NShotTimer(const unsigned int &nTimes, const unsigned int &sleepMilliseconds) 
		: nTimes_(nTimes),  sleepMilliseconds_(sleepMilliseconds)
	{};


protected:
    void startFn() override {
		{
			std::lock_guard<std::mutex> lock(this->timerMutex_);
			this->isRunning_ = true;	
		}
		this->workerThread_ = std::thread([this] {
			for (unsigned int i = 0; i < nTimes_; ++i) {
				{
					std::lock_guard<std::mutex> lock(this->timerMutex_);
					if (!this->isRunning_) {
						break;
					}
				}
				
				{
					std::lock_guard<std::mutex> lock(this->timerMutex_);
					if (this->isRunning_) {
						for (auto &amp: this->actorMessagePairs_) {
							amp->actorReceiveMessage();				
						}	
					}
				}

				std::this_thread::sleep_for(std::chrono::milliseconds(sleepMilliseconds_));
			}
			std::lock_guard<std::mutex> lock(this->timerMutex_);
			this->isRunning_ = false;
		});
	} 

	void stopFn() override {
		{
			std::lock_guard<std::mutex> lock(this->timerMutex_);
			this->isRunning_ = false;
		}
		if (this->workerThread_.joinable()) {
			this->workerThread_.join();
		}
	}

private:
	unsigned int nTimes_;
	unsigned int sleepMilliseconds_;
};

#endif
