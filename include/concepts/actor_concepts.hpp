#ifndef ACTOR_CONCEPTS_HPP
#define ACTOR_CONCEPTS_HPP

#include "message_concepts.hpp"
#include "actors/actor.hpp"

template <typename T, typename DM>
concept DerivedFromActor = DerivedFromMessage<DM> and std::derived_from<T, Actor<DM>>;

#endif
