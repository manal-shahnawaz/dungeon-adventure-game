#include "Player.h"
using namespace std;

Player::Player(string n) : Entity(n, 100, 25, 10) {
    gold = 50;
    level = 1;
    xp = 0;
    score = 0;
    bag.push_back("Steel Dagger");
}

void Player::addGold(int g) {
    gold += g;
    score += g;
}

void Player::addXP(int points) {
    xp += points;
    if (xp >= 100) {
        levelUp();
    }
}

void Player::levelUp() {
    level++;
    xp = 0;
    health = health + 20;
    attackPower = attackPower + 5;
    cout << "\n*** LEVEL UP! You are now Level " << level << " ***\n";
}

void Player::showStats() {
    cout << "\n******************************\n";
    cout << " Name  : " << name << "\n";
    cout << " HP    : " << health << "\n";
    cout << " Gold  : " << gold << "\n";
    cout << " Score : " << score << "\n";
    cout << " Level : " << level << "\n";
    cout << "******************************\n";
}

void Player::showInventory() {
    cout << "\n--- YOUR BAG ---\n";
    for (int i = 0; i < bag.size(); i++) {
        cout << " - " << bag[i] << "\n";
    }
}

int Player::getScore() { return score; }
int Player::getGold() { return gold; }

void Player::spendGold(int amount) {
    gold -= amount;
}

void Player::heal() {
    health = 100;
}