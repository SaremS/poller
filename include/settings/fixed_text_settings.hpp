#ifndef FIXED_TEXT_SETTINGS_HPP
#define FIXED_TEXT_SETTINGS_HPP

#include <string>

#include "settings.hpp"


class FixedTextSettings : public Settings {
public:
	FixedTextSettings(const std::string& text) : text_(text) {}
	std::string getText() const;
private:
	std::string text_;
};

#endif
