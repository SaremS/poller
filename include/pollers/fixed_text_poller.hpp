#ifndef FIXED_TEXT_POLLER_HPP
#define FIXED_TEXT_POLLER_HPP

#include <string>
#include <memory>

#include "pollers/poller.hpp"
#include "sinks/sink.hpp"
#include "settings/fixed_text_settings.hpp"

class FixedTextPoller : Poller {
public:
	FixedTextPoller(
			const FixedTextSettings &settings,
			std::unique_ptr<Sink> sink,
			std::unique_ptr<Logger> logger
			) : text_(settings.getText()),
				sink_(std::move(sink)),
				logger_(std::move(logger))
			{}
	
	void poll() const override;
private:
	std::string text_;
	std::unique_ptr<Sink> sink_;
	std::unique_ptr<Logger> logger_;
};

#endif
