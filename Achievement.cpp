#include "Achievement.h"
using namespace std;

Achievement::Achievement(string t, string desc, int pts, string cat) {
    title = t;
    description = desc;
    unlocked = false;
    points = pts;
    category = cat;
    dateUnlocked = "";
}

void Achievement::unlock() {
    if (!unlocked) {
        unlocked = true;
        dateUnlocked = "Session";
        cout << "\n*** ACHIEVEMENT UNLOCKED: [" << title << "] ***\n";
        cout << "    " << description << "\n";
        cout << "    +" << points << " pts | Category: " << category << "\n";
    }
}

bool Achievement::isUnlocked() { return unlocked; }

void Achievement::showAchievement() {
    cout << " [" << (unlocked ? "X" : " ") << "] "
        << title << " - " << description
        << " [" << points << "pts | " << category << "]\n";
}

string Achievement::getTitle() { return title; }
int Achievement::getPoints() { return points; }
string Achievement::getCategory() { return category; }