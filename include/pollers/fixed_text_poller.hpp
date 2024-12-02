#ifndef FIXED_TEXT_POLLER_HPP
#define FIXED_TEXT_POLLER_HPP

#include <string>
#include <memory>

#include "pollers/poller.hpp"
#include "sinks/sink.hpp"
#include "settings/fixed_text_settings.hpp"


template <DerivedFromPersister<LoggingMessage> DP>
class FixedTextPoller : Poller {
public:
	FixedTextPoller(
			const FixedTextSettings &settings,
			std::shared_ptr<Sink> sink,
			std::shared_ptr<Logger<DP>> logger
			) : text_(settings.getText()),
				sink_(std::move(sink)),
				logger_(std::move(logger))
			{}
	
	void poll() const override;
private:
	std::string text_;
	std::shared_ptr<Sink> sink_;
	std::shared_ptr<Logger<DP>> logger_;
};

#endif
