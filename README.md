# 🗡️ Dungeon Adventure Game

An **AI-powered C++ dungeon adventure game** built as a semester project for Object-Oriented Programming (OOP) at FAST-NUCES.

## 📌 About
Player explores a dungeon managed by an AI DungeonMaster. The game features a full login system, quest tracking, inventory management, enemy combat, and achievement unlocking — all persisted via file I/O.

## 🚀 Features
- **Login System** — User registration and authentication with file-based storage
- **AI DungeonMaster** — Dynamically manages dungeon rooms and events
- **Combat System** — Player vs Enemy battles with attack, defense, and health stats
- **Quest System** — Main and side quests with XP rewards
- **Inventory & Items** — Weapons and items with rarity levels and weight
- **Achievement System** — Unlockable achievements based on gameplay
- **Game Logger** — Logs all game events to file with session tracking
- **Scoreboard** — Persistent high score tracking across sessions

## 🛠️ Tech Stack
- **Language:** C++ (with Python AI module)
- **Concepts Used:** OOP (Inheritance, Polymorphism, Abstraction, Encapsulation)
- **File I/O:** .txt file persistence for users, scores, and dungeon data
- **Design:** Multi-file architecture with separate .h header and .cpp implementation files

## 🗂️ Project Structure
```
├── main.cpp              # Entry point and game loop
├── Entity.h / .cpp       # Base class for Player and Enemy
├── Player.h / .cpp       # Player class (inherits Entity)
├── Enemy.h / .cpp        # Enemy class (inherits Entity)
├── DungeonMaster.h/.cpp  # AI-controlled dungeon manager
├── Quest.h / .cpp        # Quest system with rewards
├── Item.h / .cpp         # Item and inventory management
├── Login.h / .cpp        # User login and registration
├── GameLogger.h / .cpp   # Event logging system
├── Achievement.h / .cpp  # Achievement tracking
├── ai.py                 # Python AI module integration
└── dungeon_data.txt      # Dungeon room and event data
```

## ▶️ How to Run
```bash
g++ -o dungeon main.cpp Player.cpp Enemy.cpp Entity.cpp DungeonMaster.cpp Quest.cpp Item.cpp Login.cpp GameLogger.cpp Achievement.cpp
./dungeon
```

## 👩‍💻 Author
**Manal Shahnawaz** — BS Software Engineering, FAST-NUCES (CF Campus)  
📧 manalshahnawaz1@gmail.com  
🔗 [LinkedIn](https://linkedin.com/in/manal-shahnawaz-)
