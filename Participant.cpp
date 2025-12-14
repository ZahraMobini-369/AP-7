#include "Participant.h"

Participant::Participant(int id, std::string n)
    : participantID(id), name(n) {}

int Participant::getID() const { return participantID; }
std::string Participant::getName() const { return name; }

void Participant::registerEvent(int eventID) {
    registeredEventIDs.push_back(eventID);
}