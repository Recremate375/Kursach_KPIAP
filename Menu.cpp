#include "Menu.h"

Menu::Menu()
{
    this->locale = "Russian";
    setlocale(LC_ALL, this->locale.c_str());
}

Menu::~Menu()
{
}

int Menu::DisplayMenu(int lchoise)
{
    string choise;
    bool stateConverte = false;
    int convertChoise = 0;
    cout << "Menu " << endl;
    do
    {
        try
        {
            cout << "1. ����;" << endl;
            cout << "0. ������� ����������." << endl;
            cout << ">> ";
            cin >> choise;
            convertChoise = stoi(choise);
            stateConverte = true;
        }
        catch ( const std::exception& )
        {
            cout << "������������ ����, ���������!" << endl;
            stateConverte = false;
        }
    } while ( !stateConverte );   

    return convertChoise;
}

bool Menu::SetConsoleLocale()
{
    setlocale(LC_ALL, this->locale.c_str());
    return true;
}