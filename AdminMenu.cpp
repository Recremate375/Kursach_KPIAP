#include "AdminMenu.h"

AdminMenu::AdminMenu()
{
}

AdminMenu::~AdminMenu()
{
}

int AdminMenu::DisplayMenu(int lchoise)
{
    system("CLS");
    string choise;
    bool stateConverte = false;
    int convertChoise = 0;
    do
    {
        try
        {
            if ( (((lchoise & 0xFF00) == 0x0200)) && (lchoise & 0x00FF) )
            {
                convertChoise = this->DisplayUserMenu() + (2 << 8);
            }
            else if ( ((lchoise & 0xFF00) == 0x0300) && (lchoise & 0x00FF) )
            {
                convertChoise = this->DisplaySoldierMenu() + (3 << 8);
            }
            else
            {
                cout << "Меню администратора" << endl;
                cout << "2. Меню пользователей;" << endl;
                cout << "3. Меню солдат." << endl;
                cout << "0. Выйти." << endl;
                cout << "1. Закрыть приложение." << endl;
                cout << ">> ";
                cin >> choise;
                convertChoise = stoi(choise);
                if ( convertChoise == 2 )
                {
                    convertChoise = this->DisplayUserMenu() + (convertChoise << 8);
                }
                else if ( convertChoise == 3 )
                {
                    convertChoise = this->DisplaySoldierMenu() + (convertChoise << 8);
                }
            }
            stateConverte = true;
        }
        catch ( const std::exception& )
        {
            cout << "Некорректный ввод, повторите!" << endl;
            system("pause");
            system("CLS");
            stateConverte = false;
        }
    } while ( !stateConverte );

    return convertChoise;
}

int AdminMenu::DisplaySoldierMenu()
{
    system("CLS");
    string choise;
    bool stateConverte = false;
    int convertChoise = 0;
    cout << "Меню администратора - Солдаты" << endl;
    do
    {
        try
        {
            cout << "1. Показать список солдат;" << endl;
            cout << "2. Добавить солдата;" << endl;
            cout << "3. Удалить данные о солдате;" << endl;
            cout << "4. Изменить данные солдата;" << endl;
            cout << "5. Найти солдата по ФИО;" << endl;
            cout << "6. Изменить информацию о здоровье солдата;" << endl;
            cout << "7. Изменить информацию о степени годности солдата;" << endl;
            cout << "0. Выйти." << endl;
            cout << ">> ";
            cin >> choise;
            convertChoise = stoi(choise);
            stateConverte = true;
        }
        catch ( const std::exception& )
        {
            cout << "Некорректный ввод, повторите!" << endl;
            system("pause");
            system("CLS");
            stateConverte = false;
        }
    } while ( !stateConverte );

    return convertChoise;
}

int AdminMenu::DisplayUserMenu()
{
    system("CLS");
    string choise;
    bool stateConverte = false;
    int convertChoise = 0;
    cout << "Меню администратора - Пользователи" << endl;
    do
    {
        try
        {
            cout << "1. Показать список пользователей;" << endl;
            cout << "2. Добавить пользователя;" << endl;
            cout << "3. Удалить данные о пользователе;" << endl;
            cout << "4. Изменить данные пользователя;" << endl;
            cout << "5. Найти пользователя по логину;" << endl;
            cout << "0. Выйти." << endl;
            cout << ">> ";
            cin >> choise;
            convertChoise = stoi(choise);
            stateConverte = true;
        }
        catch ( const std::exception& )
        {
            cout << "Некорректный ввод, повторите!" << endl;
            system("pause");
            system("CLS");
            stateConverte = false;
        }
    } while ( !stateConverte );

    return convertChoise;
}
