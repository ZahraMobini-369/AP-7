#include "Event.h"
#include <stdexcept>

Event::Event(int id, std::string name, std::string type, int cap)
    : eventID(id), eventName(name), eventType(type), capacity(cap) {}

int Event::getID() const { return eventID; }
std::string Event::getName() const { return eventName; }
std::string Event::getType() const { return eventType; }
int Event::getCapacity() const { return capacity; }

int Event::getParticipantCount() const {
    return registeredParticipantIDs.size();
}

bool Event::isFull() const {
    return registeredParticipantIDs.size() >= capacity;
}

void Event::addParticipant(int participantID) {
    if (isFull()) {
        throw std::runtime_error("Event capacity is full.");
    }
    registeredParticipantIDs.push_back(participantID);
}
