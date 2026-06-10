#include "Item.h"
using namespace std;

Item::Item(string n, string type, int val, float wt, string rar, int qty) {
    name = n;
    itemType = type;
    value = val;
    weight = wt;
    rarity = rar;
    quantity = qty;
}

void Item::showItem() {
    cout << " [" << itemType << "] " << name
        << " (Value: " << value << " | Wt: " << weight
        << "kg | Rarity: " << rarity
        << " | Qty: " << quantity << ")\n";
}

string Item::getName() { return name; }
string Item::getType() { return itemType; }
int Item::getValue() { return value; }
float Item::getWeight() { return weight; }
string Item::getRarity() { return rarity; }
int Item::getQuantity() { return quantity; }