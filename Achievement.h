#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H
#include <string>
#include <iostream>
using namespace std;

class Achievement {
private:
    string title;
    string description;
    bool unlocked;
    int points;
    string category;
    string dateUnlocked;

public:
    Achievement(string t, string desc, int pts = 10, string cat = "General");
    void unlock();
    bool isUnlocked();
    void showAchievement();
    string getTitle();
    int getPoints();
    string getCategory();
};

#endif