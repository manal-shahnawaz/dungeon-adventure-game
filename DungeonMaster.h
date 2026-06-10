#ifndef DUNGEON_MASTER_H
#define DUNGEON_MASTER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Player;

class DungeonMaster {
private:
    vector<string> rooms;
    string dungeonName;     // Added: dungeon ka naam
    string difficulty;      // Added: Easy, Medium, Hard
    int floorsCleared;      // Added: total cleared floors
    int totalGoldSpawned;   // Added: total gold generated
    int currentFloor;       // Added: current floor number

public:
    DungeonMaster(string name = "Shadow Keep", string diff = "Medium");
    void loadRooms();
    string getRoom(int index);
    int totalRooms();
    void saveScore(string playerName, int score);
    void showScoreboard();
    void runAI(string action);
    void combat(Player& player);
    void showDungeonInfo();
    int getCurrentFloor();
    void nextFloor();
};

#endif