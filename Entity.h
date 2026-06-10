#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using namespace std;

class Entity {
protected:
    string name;
    int health;
    int attackPower;
    int defense;

public:
    Entity(string n, int h, int atk, int def);
    virtual void showStats() = 0;
    string getName();
    int getHealth();
    int getAtk();
    void setHealth(int h);
};

#endif