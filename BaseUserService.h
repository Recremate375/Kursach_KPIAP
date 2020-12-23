#pragma once

#include <vector>
#include "User.h"

class BaseUserService
{
protected :
    void Find();
private:
    vector<User> users_;
    string userFileName_;
    string Split(string& s, string delimiter);
    int LoadData();
    int SaveData();
public:
    BaseUserService();
    BaseUserService(string userFileName);
    void ShowAll();
    bool AddUser();
    bool DeleteUser();
    bool UpdateUser();
    int FindFirstUser(string login);
    bool FindUser();
    User* GetUser(string login, string password);
    ~BaseUserService();
};
