#ifndef QUEST_H
#define QUEST_H
#include <string>
#include <iostream>
using namespace std;

class Quest {
private:
    string title;
    string description;
    int goldReward;
    bool completed;
    string questType;
    int xpReward;

public:
    Quest(string t, string desc, int reward, string type = "Side", int xp = 30);
    void showQuest();
    void completeQuest();
    bool isCompleted();
    int getReward();
    int getXPReward();
    string getTitle();
    string getQuestType();
};

#endif