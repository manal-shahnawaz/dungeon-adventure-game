#include "Quest.h"
using namespace std;

Quest::Quest(string t, string desc, int reward, string type, int xp) {
    title = t;
    description = desc;
    goldReward = reward;
    completed = false;
    questType = type;
    xpReward = xp;
}

void Quest::showQuest() {
    cout << "\n[QUEST - " << questType << "] " << title << "\n";
    cout << "  " << description << "\n";
    cout << "  Reward: " << goldReward << " Gold | " << xpReward << " XP\n";
    cout << "  Status: " << (completed ? "Done" : "Active") << "\n";
}

void Quest::completeQuest() {
    completed = true;
    cout << "[+] Quest Complete: " << title
        << "! +" << goldReward << " Gold, +" << xpReward << " XP\n";
}

bool Quest::isCompleted() { return completed; }
int Quest::getReward() { return goldReward; }
int Quest::getXPReward() { return xpReward; }
string Quest::getTitle() { return title; }
string Quest::getQuestType() { return questType; }