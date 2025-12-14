#ifndef MANAGER_H
#define MANAGER_H

#include "Event.h"
#include "Participant.h"
#include <map>
#include <vector>

class Manager {
private:
    std::map<int, Event> events;           
    std::map<int, Participant> participants; 

public:
    void addEvent(int id, std::string name, std::string type, int capacity);
    void addParticipant(int id, std::string name);

    // ثبت نام با مدیریت خطا
    void registerParticipantToEvent(int participantID, int eventID);

    // توابع نمایش لیست‌ها
    void listEventsSortedByType() const;
    void listEventsSortedByParticipantCount() const;
};

#endif
