#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(string n, int h, int atk, int def, string t, int reward)
    : Entity(n, h, atk, def) {
    type = t;
    goldReward = reward;
}

void Enemy::showStats() {
    cout << "\n[Enemy] " << name << " (" << type << ")"
        << " | HP: " << health
        << " | ATK: " << attackPower << "\n";
}

string Enemy::getType() {
    return type;
}

int Enemy::getGoldReward() {
    return goldReward;
}
