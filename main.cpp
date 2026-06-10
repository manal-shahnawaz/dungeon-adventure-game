#include <iostream>
#include <ctime>
#include "Player.h"
#include "DungeonMaster.h"
#include "Login.h"
#include "Enemy.h"
#include "Quest.h"
#include "Item.h"
#include "GameLogger.h"
#include "Achievement.h"
using namespace std;

int main() {
    srand(time(0));

    DungeonMaster dm("Shadow Keep", "Medium");
    dm.loadRooms();

    cout << "****************************\n";
    cout << "      AI DUNGEON MASTER\n";
    cout << "****************************\n";

    Login loginSystem;
    bool loggedIn = false;
    while (!loggedIn) {
        loggedIn = loginSystem.showLoginMenu();
    }

    string playerName = loginSystem.getCurrentUser();
    if (playerName == "Guest") {
        cout << "Enter hero name: ";
        cin >> playerName;
    }

    bool playAgain = true;

    while (playAgain) {

        Player player(playerName);

        // GameLogger
        GameLogger logger("gamelog.txt", (int)(time(0) % 1000), 500);
        logger.log("Game started by: " + playerName);

        // Quest
        Quest q1("Monster Slayer", "Kill a monster in the dungeon", 50, "Main", 40);
        q1.showQuest();

        // Items
        Item sword("Iron Sword", "Weapon", 30, 2.5f, "Common", 1);
        Item potion("Health Potion", "Consumable", 20, 0.3f, "Common", 3);
        cout << "\n--- Starting Items ---\n";
        sword.showItem();
        potion.showItem();

        // Enemy preview
        Enemy goblin("Goblin", 60, 12, 5, "Minion", 25);
        goblin.showStats();

        // Achievements
        Achievement achMonsterSlayer("Monster Slayer", "Kill your first monster", 20, "Combat");
        Achievement achRichAdventurer("Rich Adventurer", "Collect 100 gold", 15, "Wealth");
        Achievement achSurvivor("Survivor", "Survive with low HP", 25, "Combat");

        dm.showDungeonInfo();
        dm.runAI(playerName + " enters the dungeon.");

        int choice;
        while (player.getHealth() > 0) {
            player.showStats();
            cout << "\n[1] Explore  [2] Shop  [3] Bag  [4] Scores  [5] Achievements  [6] Quit\nAction: ";
            cin >> choice;

            if (choice == 1) {
                int idx = rand() % dm.totalRooms();
                cout << "\n" << dm.getRoom(idx) << "\n";
                int roll = rand() % 3;
                if (roll == 0) {
                    dm.combat(player);
                    if (player.getHealth() > 0) {
                        achMonsterSlayer.unlock();
                        logger.log(playerName + " killed a monster.");

                        if (!q1.isCompleted()) {
                            q1.completeQuest();
                            player.addGold(q1.getReward());
                            player.addXP(q1.getXPReward());
                            logger.log(playerName + " completed quest: " + q1.getTitle());
                        }
                    }
                }
                else if (roll == 1) {
                    cout << "[+] Found 20 Gold!\n";
                    player.addGold(20);
                    logger.log(playerName + " found gold.");
                }
                else {
                    dm.runAI(playerName + " walks through a quiet hall.");
                }

                if (player.getGold() >= 100) {
                    achRichAdventurer.unlock();
                }

                if (player.getHealth() > 0 && player.getHealth() <= 20) {
                    achSurvivor.unlock();
                }
            }
            else if (choice == 2) {
                if (player.getGold() >= 40) {
                    player.spendGold(40);
                    player.heal();
                    cout << "[+] Healed! (-40 gold)\n";
                    logger.log(playerName + " used shop to heal.");
                }
                else {
                    cout << "[!] Need 40 gold to heal.\n";
                }
            }
            else if (choice == 3) {
                player.showInventory();
            }
            else if (choice == 4) {
                dm.showScoreboard();
            }
            else if (choice == 5) {
                cout << "\n--- ACHIEVEMENTS ---\n";
                achMonsterSlayer.showAchievement();
                achRichAdventurer.showAchievement();
                achSurvivor.showAchievement();
            }
            else {
                break;
            }
        }

        if (player.getHealth() <= 0) {
            cout << "\n[GAME OVER] You have been defeated!\n";
            logger.log(playerName + " died in the dungeon.");
        }

        dm.saveScore(player.getName(), player.getScore());
        logger.log("Game ended. Final score: " + to_string(player.getScore()));
        cout << "Final Score: " << player.getScore() << "\n";

        cout << "\n[1] Play Again  [2] Exit\nChoice: ";
        int restart;
        cin >> restart;
        if (restart == 1) {
            playAgain = true;
            cout << "\n--- RESTARTING GAME ---\n";
            logger.log(playerName + " restarted the game.");
        }
        else {
            playAgain = false;
            cout << "Score saved. Goodbye!\n";
        }

    }
 
    return 0;
}