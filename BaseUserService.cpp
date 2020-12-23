#include <fstream>
#include <sstream>
#include <iostream>

#include "BaseUserService.h"

string BaseUserService::Split(string& s, string delimiter)
{
    size_t pos_start = 0, pos_end;
    string token;

    if ( (pos_end = s.find(delimiter, pos_start)) != string::npos )
    {
        token = s.substr(pos_start, pos_end - pos_start);
        s = s.substr(pos_end - pos_start + 1, s.length());
    }
    return token;
}

BaseUserService::BaseUserService()
{
    this->userFileName_ = "UserInfo.txt";
    this->LoadData();
}

BaseUserService::BaseUserService(string userFileName)
{
    this->userFileName_ = userFileName;
}

void BaseUserService::ShowAll()
{
    if ( !this->users_.empty() )
    {
        for (int i = 0;i < this->users_.size(); i++ )
        {
            cout << i+1 << ") " << this->users_[i];
        }
    }
    else
    {
        cout << "Список пользователей пуст!" << endl;
    }
    system("pause");
}

bool BaseUserService::AddUser()
{
    string login, password;
    int accessLevel = 0;
    cout << "Введите логин: " << endl << ">> ";
    cin >> login;
    cout << "Введите пароль: " << endl << ">> ";
    cin >> password;
    cout << "Введите уровень доступа(1-4): " << endl << ">> ";
    try
    {
        cin >> accessLevel;
    }
    catch ( const std::exception& )
    {
        accessLevel = 0;
    }
    
    this->users_.push_back(User(login, password, accessLevel));
    this->SaveData();
    return false;
}

bool BaseUserService::DeleteUser()
{
    string login;
    int index = -1;

    cout << "Введите логин для удаления: " << endl << ">> ";
    cin >> login;
    if ( !this->users_.empty() )
    {
        index = this->FindFirstUser(login);
        if ( index >= 0 )
        {
            this->users_.erase(this->users_.begin() + index);
            this->SaveData();
            cout << "Пользователь успешно удален!" << endl;
        }
        else
        {
            cout << "Пользователь с данным логином не найден!" << endl;
        }
    }
    else
    {
        cout << "Список пользователей пуст!" << endl;
    }
    system("pause");
    return false;
}


bool BaseUserService::UpdateUser()
{
    int index;
    bool goodIndex = false;
   
    cout << "Выберите номер пользователя, которого желаете изменить: " << endl;
    this->ShowAll();
    do
    {
        try
        {
            cout << ">> "; 
            cin >> index;
            index--;
            if ( index < this->users_.size() )
            {
                goodIndex = true;
            }
        }
        catch ( const std::exception& )
        {

        }
    } while ( !goodIndex );

    string login, password;
    int accessLevel;
    cout << " Введите новый логин: " << endl << ">>";
    cin >> login;
    cout << " Введите новый пароль: " << endl << ">>";
    cin >> password;
    cout << "Введите новый уровень доступа: " << endl << ">>";
    cin >> accessLevel;
    this->users_[index] = User(login, password, accessLevel);
    return false;
}

int BaseUserService::FindFirstUser(string login)
{
    for ( int i = 0; i < this->users_.size(); i++ )
    {
        if ( !login.compare(this->users_[i].GetLogin()) )
        {
            return i;
        }
    }
    return -1;
}

bool BaseUserService::FindUser()
{
    string login;
    int index = 0;

    cout << "Введите логин для поиска: " << endl << ">> ";
    cin >> login;
    index = this->FindFirstUser(login);
    if (index  >= 0 )
    {
        cout << this->users_[index] << endl;
    }
    else
    {
        cout << " Нет пользователя с заданым логином!" << endl;
    }
    system("pause");
    return false;
}

/**
 * @brief Funtion that's load data from file, that's contain all user info.
 * 
 * @return int return status.
 * 0 - file is not open;
 * 1 - all is good;
 */
int BaseUserService::LoadData()
{
    ifstream fin;

    fin.open(this->userFileName_);
    if ( !fin.is_open() )
    {
        return 0;
    }
    else
    {
        string dataFromFile;
        string delimiter = "/";

        getline(fin, dataFromFile);

        while ( !fin.eof() )
        {
            getline(fin, dataFromFile);

            string login, password, stringAcssessLevel;
            int acssessLevel = 0;
            try
            {
                login = Split(dataFromFile, delimiter);
                password = Split(dataFromFile, delimiter);
                stringAcssessLevel = Split(dataFromFile, delimiter);
                acssessLevel = stoi(stringAcssessLevel);
                if ( acssessLevel )
                {
                    this->users_.push_back(User(login, password, acssessLevel));
                }
            }
            catch( const exception& e )
            {
                cout << e.what() << endl;
            }
        }
    }
    fin.close();
    return 1;
}
int BaseUserService::SaveData()
{
    ofstream fin;

    fin.open(this->userFileName_);
    if ( !fin.is_open() )
    {
        return 0;
    }
    else
    {
        string dataToFile;
        string delimiter = "/";

        fin << "login / password / accessLevel";
        for ( int i = 0; i < this->users_.size(); i++ )
        {
            fin << endl << this->users_[i].GetLogin() << "/" << this->users_[i].GetPassword()  << "/" << this->users_[i].GetAccessLevel() << "/";
        }
    }
    fin.close();
    return 1;
}
/**
 * @brief function that's give you User object if input parametr is correct and 
 * if this service has this user in local database.
 * 
 * @param login string that is contain login for the user
 * @param password string that is contain password for the user
 * @return User* class object with access level and another info
 */
User* BaseUserService::GetUser(string login, string password)
{
    User temp_user(login, password, 0);
    for ( auto i : this->users_ )
    {
        if ( i == temp_user )
        {
            i.GetAccessLevel();
            return (new User(temp_user.GetLogin(), temp_user.GetPassword(), i.GetAccessLevel()));
        }
    }
    return (new User(temp_user.GetLogin(), temp_user.GetPassword(), temp_user.GetAccessLevel()));
}

/**
 * @brief Destroy the Base User Service:: Base User Service object
 * 
 */
BaseUserService::~BaseUserService()
{
}
