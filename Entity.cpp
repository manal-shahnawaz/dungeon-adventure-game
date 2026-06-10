#include "Entity.h"

Entity::Entity(string n, int h, int atk, int def) {
    name = n;
    health = h;
    attackPower = atk;
    defense = def;
}

string Entity::getName() {
    return name;
}

int Entity::getHealth() {
    return health;
}

int Entity::getAtk() {
    return attackPower;
}

void Entity::setHealth(int h) {
    health = h;
}