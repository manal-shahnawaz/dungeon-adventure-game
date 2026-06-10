#include "DungeonMaster.h"
#include "Player.h"
using namespace std;

DungeonMaster::DungeonMaster(string name, string diff) {
    dungeonName = name;
    difficulty = diff;
    floorsCleared = 0;
    totalGoldSpawned = 0;
    currentFloor = 1;
}

void DungeonMaster::loadRooms() {
    ifstream fin("dungeon_data.txt");
    if (!fin) {
        ofstream fout("dungeon_data.txt");
        vector<string> types = {
            "Dark Corridor", "Torch-lit Hall", "Abandoned Chamber",
            "Flooded Passage", "Bone-covered Floor", "Mossy Tunnel",
            "Crumbling Bridge", "Hidden Alcove", "Echoing Cavern",
            "Stone Stairway"
        };
        for (int i = 1; i <= 100; i++) {
            fout << "Room_" << i << ": " << types[(i - 1) % 10] << "\n";
        }
        fout.close();
    }
    rooms.clear();
    ifstream fin2("dungeon_data.txt");
    string line;
    while (getline(fin2, line)) {
        rooms.push_back(line);
    }
    fin2.close();
}

string DungeonMaster::getRoom(int index) {
    if (index >= 0 && index < (int)rooms.size()) {
        return rooms[index];
    }
    return "Unknown Room";
}

int DungeonMaster::totalRooms() {
    return rooms.size();
}

void DungeonMaster::saveScore(string playerName, int score) {
    ofstream fout("scoreboard.txt", ios::app);
    fout << playerName << ": " << score << "\n";
    fout.close();
}

void DungeonMaster::showScoreboard() {
    ifstream fin("scoreboard.txt");
    string line;
    cout << "\n--- HIGH SCORES ---\n";
    bool empty = true;
    while (getline(fin, line)) {
        empty = false;
        cout << " " << line << "\n";
    }
    if (empty) {
        cout << " No scores yet!\n";
    }
    fin.close();
}

void DungeonMaster::runAI(string action) {
    ofstream fout("prompt.txt");
    fout << action;
    fout.close();
    system("python ai.py");
    ifstream fin("response.txt");
    string res;
    cout << "\n[Narrator] ";
    if (getline(fin, res)) {
        cout << "\"" << res << "\"\n";
    }
    fin.close();
}

void DungeonMaster::combat(Player& player) {
    int enemyHP = 50 + (rand() % 40);
    int enemyAtk = 15 + (rand() % 10);

    cout << "\n[!] A monster appears! Enemy HP: " << enemyHP << "\n";
    runAI("A monster attacks " + player.getName());

    while (enemyHP > 0 && player.getHealth() > 0) {
        cout << "\nYour HP: " << player.getHealth();
        cout << " | Enemy HP: " << enemyHP << "\n";
        cout << "[1] Attack  [2] Block\nAction: ";

        int action;
        cin >> action;

        if (action == 1) {
            int dmg = player.getAtk() - (rand() % 5);
            enemyHP -= dmg;
            cout << ">> You hit for " << dmg << " damage!\n";
        }
        else {
            cout << ">> You block!\n";
        }

        if (enemyHP > 0) {
            int taken = (action == 2) ? (enemyAtk / 3) : enemyAtk;
            player.setHealth(player.getHealth() - taken);
            cout << ">> Enemy hits you for " << taken << "\n";
        }
    }

    if (player.getHealth() > 0) {
        int goldReward = 30;
        totalGoldSpawned += goldReward;
        cout << "\n[WIN] +" << goldReward << " Gold, +60 XP!\n";
        player.addGold(goldReward);
        player.addXP(60);
        nextFloor();
    }
}

void DungeonMaster::showDungeonInfo() {
    cout << "\n--- DUNGEON INFO ---\n";
    cout << " Name      : " << dungeonName << "\n";
    cout << " Difficulty: " << difficulty << "\n";
    cout << " Floor     : " << currentFloor << "\n";
    cout << " Cleared   : " << floorsCleared << " floors\n";
    cout << " Gold Spawn: " << totalGoldSpawned << " total\n";
}

int DungeonMaster::getCurrentFloor() { return currentFloor; }

void DungeonMaster::nextFloor() {
    floorsCleared++;
    currentFloor++;
    cout << "\n[+] Entering Floor " << currentFloor << "!\n";
}