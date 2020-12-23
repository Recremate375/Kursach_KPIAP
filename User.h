#ifndef __USER__
#define __USER__

#include <string>

using namespace std;

class User
{
private:
    string login_;
    string password_;
    int accessLevel_;
public:
    User();
    User(string login, string password, int accessLevel);
    ~User();
    friend bool operator== (const User &u1, const User &u2);
    int GetAccessLevel();
    string GetLogin();
    string GetPassword();
    friend ostream& operator<<(ostream &out, User &user);
};

#endif /*__USER__*/
