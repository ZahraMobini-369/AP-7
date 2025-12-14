#include "Manager.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

void Manager::addEvent(int id, std::string name, std::string type, int capacity) {
    if (events.find(id) != events.end()) {
        std::cout << "Error: Event ID " << id << " already exists.\n";
        return;
    }
    events.emplace(id, Event(id, name, type, capacity));
}

void Manager::addParticipant(int id, std::string name) {
    if (participants.find(id) != participants.end()) {
        std::cout << "Error: Participant ID " << id << " already exists.\n";
        return;
    }
    participants.emplace(id, Participant(id, name));
}

void Manager::registerParticipantToEvent(int participantID, int eventID) {
    // 1. بررسی وجود شرکت‌کننده
    auto pIt = participants.find(participantID);
    if (pIt == participants.end()) {
        throw std::invalid_argument("Error: Participant with ID " + std::to_string(participantID) + " not found.");
    }

   // 2. بررسی وجود رویداد
    auto eIt = events.find(eventID);
    if (eIt == events.end()) {
        throw std::invalid_argument("Error: Event with ID " + std::to_string(eventID) + " not found.");
    }

    // 3. بررسی ظرفیت رویداد
    if (eIt->second.isFull()) {
        throw std::runtime_error("Error: Event '" + eIt->second.getName() + "' is at full capacity.");
    }

    // انجام عملیات ثبت نام
    eIt->second.addParticipant(participantID); // افزودن شرکت‌کننده به رویداد
    pIt->second.registerEvent(eventID);        // افزودن رویداد به لیست شرکت‌کننده

    std::cout << "Success: Participant " << pIt->second.getName()
              << " registered for " << eIt->second.getName() << ".\n";
}

// نمایش رویدادها مرتب شده بر اساس نوع
void Manager::listEventsSortedByType() const {
    std::vector<Event> eventList;
    for (const auto& pair : events) {
        eventList.push_back(pair.second);
    }

    std::sort(eventList.begin(), eventList.end(), [](const Event& a, const Event& b) {
        return a.getType() < b.getType();
    });

    std::cout << "\n--- Events Sorted by Type ---\n";
    for (const auto& e : eventList) {
        std::cout << "Type: " << e.getType() << " | Name: " << e.getName()
                  << " | ID: " << e.getID() << "\n";
    }
}

// نمایش رویدادها مرتب شده بر اساس تعداد شرکت‌کنندگان
void Manager::listEventsSortedByParticipantCount() const {
    std::vector<Event> eventList;
    for (const auto& pair : events) {
        eventList.push_back(pair.second);
    }

    std::sort(eventList.begin(), eventList.end(), [](const Event& a, const Event& b) {
        return a.getParticipantCount() > b.getParticipantCount(); // نزولی
    });

    std::cout << "\n--- Events Sorted by Popularity (Participant Count) ---\n";
    for (const auto& e : eventList) {
        std::cout << "Count: " << e.getParticipantCount() << " | Name: " << e.getName()
                  << " | ID: " << e.getID() << "\n";
    }
}
