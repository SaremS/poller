#ifndef PERSISTER_HPP
#define PERSISTER_HPP

#include <queue>
#include <type_traits>

#include "messages/message.hpp"


template <typename T>
concept DerivedFromMessage = std::derived_from<T, Message>;


template <DerivedFromMessage DM>
class Persister {
public:
	virtual ~Persister() = default;
	virtual void persistQueueAsJson(const std::queue<DM> &messageQueue) = 0;
	virtual std::queue<DM> loadPersistedJsonQueue() const = 0;
};

#endif
