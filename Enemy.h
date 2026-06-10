#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <string>
using namespace std;

class Enemy : public Entity {
private:
    string type;
    int goldReward;

public:
    Enemy(string n, int h, int atk, int def, string t, int reward);
    void showStats() override;
    string getType();
    int getGoldReward();
};

#endif
