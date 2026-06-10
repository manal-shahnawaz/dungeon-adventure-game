#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Login {
private:
    string currentUser;
    vector<string> usernames;
    vector<string> passwords;

    void loadUsers();
    void saveUser(string uname, string pass);
    bool usernameExists(string uname);
    bool checkPassword(string uname, string pass);

public:
    Login();
    bool registerUser();
    bool loginUser();
    string getCurrentUser();
    bool showLoginMenu();
};

#endif