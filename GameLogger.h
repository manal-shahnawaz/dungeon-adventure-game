#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class GameLogger {
private:
    string logFile;
    int logCount;
    string logLevel;
    int sessionID;
    string createdAt;
    int maxLines;

public:
    GameLogger(string filename, int session = 0, int maxL = 500);
    void log(string message);
    void showLog();
    void clearLog();
    int getLogCount();
    string getLogLevel();
    void setLogLevel(string level);
};

#endif