#include "GameLogger.h"
using namespace std;

GameLogger::GameLogger(string filename, int session, int maxL) {
    logFile = filename;
    logCount = 0;
    logLevel = "INFO";
    sessionID = session;
    createdAt = "Session_" + to_string(session);
    maxLines = maxL;
}

void GameLogger::log(string message) {
    ofstream fout(logFile, ios::app);
    fout << "[" << logLevel << "][S" << sessionID << "] " << message << "\n";
    fout.close();
    logCount++;
    if (logCount >= maxLines) {
        cout << "[Logger] Warning: Log reaching max limit\n";
    }
}

void GameLogger::showLog() {
    ifstream fin(logFile);
    string line;
    cout << "\n--- GAME LOG (Session " << sessionID << ") ---\n";
    while (getline(fin, line)) {
        cout << " " << line << "\n";
    }
    fin.close();
}

void GameLogger::clearLog() {
    ofstream fout(logFile);
    fout.close();
    logCount = 0;
    cout << "[Log cleared]\n";
}

int GameLogger::getLogCount() { return logCount; }
string GameLogger::getLogLevel() { return logLevel; }
void GameLogger::setLogLevel(string level) { logLevel = level; }