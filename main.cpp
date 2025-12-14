#include <iostream>
#include "Manager.h"

int main() {
    Manager systemManager;

    // 1. افزودن رویدادها
    systemManager.addEvent(101, "Tech Talk", "Conference", 2); // ظرفیت کم برای تست خطا
    systemManager.addEvent(102, "Music Fest", "Concert", 500);
    systemManager.addEvent(103, "Art Expo", "Exhibition", 100);

    // 2. افزودن شرکت‌کنندگان
    systemManager.addParticipant(1, "Ali");
    systemManager.addParticipant(2, "Sara");
    systemManager.addParticipant(3, "Reza");

    std::cout << "Starting Registration Process...\n\n";

    // 3. تست ثبت‌نام‌های موفق و مدیریت خطاها (Try-Catch)
    try {
        // ثبت نام موفق
        systemManager.registerParticipantToEvent(1, 101);
        systemManager.registerParticipantToEvent(2, 101);
        systemManager.registerParticipantToEvent(1, 102);

        // تست خطا: تلاش برای ثبت نام در رویدادی که ظرفیتش پر شده (Tech Talk ظرفیتش 2 بود)
        std::cout << "\nAttempting to register Reza into full Tech Talk event:\n";
        systemManager.registerParticipantToEvent(3, 101);

    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION CAUGHT: " << e.what() << "\n"; 
    }

    try {
        // تست خطا: شناسه شرکت‌کننده نامعتبر
        std::cout << "\nAttempting to register invalid participant ID 99:\n";
        systemManager.registerParticipantToEvent(99, 102);

    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION CAUGHT: " << e.what() << "\n";
    }

    // 4. نمایش لیست‌ها
    systemManager.listEventsSortedByType();
    systemManager.listEventsSortedByParticipantCount();

    return 0;
}