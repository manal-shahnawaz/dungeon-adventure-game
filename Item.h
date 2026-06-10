#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string name;
    string itemType;
    int value;
    float weight;      // Added: weight of item in kg
    string rarity;     // Added: Common, Rare, Epic
    int quantity;      // Added: how many of this item

public:
    Item(string n, string type, int val, float wt = 1.0, string rar = "Common", int qty = 1);
    void showItem();
    string getName();
    string getType();
    int getValue();
    float getWeight();
    string getRarity();
    int getQuantity();
};

#endif