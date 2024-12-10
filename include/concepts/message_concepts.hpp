#ifndef MESSAGE_CONCEPTS_HPP
#define MESSAGE_CONCEPTS_HPP

#include "messages/message.hpp"
#include "sinks/sink_message.hpp"

template <typename T>
concept DerivedFromMessage = std::derived_from<T, Message>;

template <typename T>
concept DerivedFromSinkableMessage = std::derived_from<T, SinkableMessage>;

#endif
