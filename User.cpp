#include "User.h"
#include <iomanip>

User::User(string login, string password, int accessLevel)
{
    this->login_ = login;
    this->password_ = password;
    this->accessLevel_ = accessLevel;
}

User::User()
{
    this->login_ = "guest";
    this->password_ = "guest";
    this->accessLevel_ = 0;
}

User::~User()
{
}

int User::GetAccessLevel()
{
    return this->accessLevel_;
}

string User::GetLogin()
{
    return this->login_;
}

string User::GetPassword()
{
    return this->password_;
}

bool operator== (const User &u1, const User &u2)
{
    return ((!u1.login_.compare(u2.login_)) && 
            (!u1.password_.compare(u2.password_)));
}

ostream& operator<<(ostream &out, User &user)
{
    return out << "Уровень доступа : " << setw(3) << user.GetAccessLevel() << " Логин : " << setw(10) << user.GetLogin()
               << " Пароль : " << setw(10) <<  user.GetPassword() << endl;
}
