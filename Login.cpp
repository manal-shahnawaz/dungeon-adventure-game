#include "Login.h"
using namespace std;

Login::Login() {
    currentUser = "";
}

void Login::loadUsers() {
    usernames.clear();
    passwords.clear();
    ifstream fin("users.txt");
    string uname, pass;
    while (fin >> uname >> pass) {
        usernames.push_back(uname);
        passwords.push_back(pass);
    }
    fin.close();
}

void Login::saveUser(string uname, string pass) {
    ofstream fout("users.txt", ios::app);
    fout << uname << " " << pass << "\n";
    fout.close();
}

bool Login::usernameExists(string uname) {
    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == uname) {
            return true;
        }
    }
    return false;
}

bool Login::checkPassword(string uname, string pass) {
    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == uname && passwords[i] == pass) {
            return true;
        }
    }
    return false;
}

bool Login::registerUser() {
    loadUsers();
    string uname, pass;
    cout << "\n--- REGISTER ---\n";
    cout << "Enter username: ";
    cin >> uname;
    if (usernameExists(uname)) {
        cout << "[!] Username already taken.\n";
        return false;
    }
    cout << "Enter password: ";
    cin >> pass;
    saveUser(uname, pass);
    cout << "[+] Account created!\n";
    currentUser = uname;
    return true;
}

bool Login::loginUser() {
    loadUsers();
    string uname, pass;
    cout << "\n--- LOGIN ---\n";
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;
    if (checkPassword(uname, pass)) {
        cout << "[+] Welcome, " << uname << "!\n";
        currentUser = uname;
        return true;
    }
    cout << "[!] Wrong username or password.\n";
    return false;
}

string Login::getCurrentUser() {
    return currentUser;
}

bool Login::showLoginMenu() {
    int choice;
    cout << "\n[1] Login\n[2] Register\n[3] Guest\nChoice: ";
    cin >> choice;
    if (choice == 1) return loginUser();
    if (choice == 2) return registerUser();
    currentUser = "Guest";
    return true;
}