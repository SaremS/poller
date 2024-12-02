#ifndef MESSAGE_CONCEPTS_HPP
#define MESSAGE_CONCEPTS_HPP

#include "messages/message.hpp"

template <typename T>
concept DerivedFromMessage = std::derived_from<T, Message>;

#endif
