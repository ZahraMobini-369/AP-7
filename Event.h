#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

class Event {
private:
    int eventID;
    std::string eventName;
    std::string eventType;
    int capacity;
    std::vector<int> registeredParticipantIDs; // لیست شناسه شرکت‌کنندگان

public:
    Event(int id, std::string name, std::string type, int cap);

    // Getters
    int getID() const;
    std::string getName() const;
    std::string getType() const;
    int getCapacity() const;
    int getParticipantCount() const;

    // متدهای مدیریتی
    bool isFull() const;
    void addParticipant(int participantID);
};

#endif