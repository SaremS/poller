#ifndef POLLER_HPP 
#define POLLER_HPP

#include "sinks/sink.hpp"
#include "settings/settings.hpp"
#include "loggers/logger.hpp"

class Poller {
public:
	virtual ~Poller() = default;
	virtual void poll() const = 0;
};

#endif
