#include "MenuService.h"
#include "AdminMenu.h"
#include "Menu.h"
#include "Debug.h"

MenuService::MenuService()
{
    this->currentUser_ = new User();
    this->menu_ = new Menu();
}

MenuService::~MenuService()
{
}


bool MenuService::DisplayMenu()
{
    static bool authorizate = false;
    int choise = 0;
    static int lastchoise = 0;
    static bool display = false;

    choise = this->menu_->DisplayMenu(lastchoise);
    
    if ( !authorizate )
    {
        if ( choise )
        {
            display = this->Authorization();
            if ( display )
            {
                authorizate = true;
            }
            else
            {
                authorizate = false;
            }
        }
        else
        {
            display = false;
        }
    } 
    else
    {
        switch ( choise )
        {
        case 0:
        {
            this->menu_ = new Menu();
            authorizate = false;
            break;
        }        
        case 1:
        {
            display = false;
            break;
        }
        case 0x201:
        {
            this->baseUS_.ShowAll();
            break;
        }        
        case 0x202:
        {
            this->baseUS_.AddUser();
            break;
        }
        case 0x203:
        {
            this->baseUS_.DeleteUser();
            break;
        }
        case 0x204:
        {
            this->baseUS_.UpdateUser();
            break;
        }
        case 0x205:
        {
            this->baseUS_.FindUser();
            break;
        }
        case 0x301:
        {
            this->soldBS_.show();
            break;
        }
        case 0x302:
        {
            this->soldBS_.CreateSoldier();
            break;
        }        
        case 0x303:
        {
            this->soldBS_.DeleteSoldier();
            break;
        }        
        case 0x304:
        {
            this->soldBS_.UpdateSoldier();
            break;
        }        
        case 0x305:
        {
            this->soldBS_.FindSoldier();
            break;
        }        
        case 0x306:
        {
            this->soldBS_.UpdateSoldierHealth();
            break;
        }        
        case 0x307:
        {
            this->soldBS_.UpdateSoldierService();
            break;
        }
        case 0x308:
        {
            this->soldBS_.ReadSoldierHealth();
            break;
        }
        default:
            break;
        }
    }
    lastchoise = choise;
    return display;
}
bool MenuService::Authorization()
{
    string login, password; 
    int countOfChoise = 0;
    rewind(stdin);
    do
    {
        #ifndef DEBUG
        cout << "Введите логин: ";
        cin >> login;
        cout << "Введите пароль: ";
        cin >> password;
        #else
        login = "admin";
        password = "admin";
        #endif
        this->currentUser_ = this->baseUS_.GetUser(login, password);
        if ( !this->currentUser_->GetAccessLevel() )
        {
            cout << "Неправильный логин или пароль!" << endl;
            countOfChoise++;
        }
        else
        {
            this->SetMenu();
            return true;
        }
    } while ( (countOfChoise < 3));
    return false;
}

void MenuService::SetMenu()
{
    switch ( this->currentUser_->GetAccessLevel() )
    {
        case 1:
        {
            this->menu_ = new AdminMenu();
            break;
        }
        default:
        {
            this->menu_ = new Menu();
        }
    }
}


