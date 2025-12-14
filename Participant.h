#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <vector>

class Participant {
private:
    int participantID;
    std::string name;
    std::vector<int> registeredEventIDs; // لیست شناسه رویدادهای ثبت‌نام شده

public:
    Participant(int id, std::string n);

    // Getters
    int getID() const;
    std::string getName() const;

    // متد ثبت رویداد برای شرکت‌کننده
    void registerEvent(int eventID);
};

#endif