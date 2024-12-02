#ifndef PERSISTING_ACTOR_HPP
#define PERSISTING_ACTOR_HPP


#include <queue>
#include <type_traits>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include "actor.hpp"
#include "messages/message.hpp"
#include "persisters/persister.hpp"
#include "concepts/message_concepts.hpp"
#include "concepts/persister_concepts.hpp"


template <DerivedFromMessage DM, DerivedFromPersister<DM> DP>
class PersistingActor: public Actor<DM> {
public:
	PersistingActor(const DP &persister) : Actor<DM>(), persister_(persister) {
		std::queue<DM> loadedQueue = persister_.loadPersistedJsonQueue();
		loadIntoQueue(loadedQueue);
	}


protected:
	void executeOnQueueChange(const std::queue<DM> &updatedQueue) const override {
		persister_.persistQueue(updatedQueue);
	} 

private:
	DP persister_;
};


#endif
