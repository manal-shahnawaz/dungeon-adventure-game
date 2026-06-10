#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <vector>
#include <iostream>
using namespace std;

class Player : public Entity {
private:
    int gold;
    int level;
    int xp;
    int score;
    vector<string> bag;

public:
    Player(string n);
    void addGold(int g);
    void addXP(int points);
    void levelUp();
    void showStats() override;
    void showInventory();
    int getScore();
    int getGold();
    void spendGold(int amount);
    void heal();
};

#endif