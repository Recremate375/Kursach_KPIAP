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
                cout << "���� ��������������" << endl;
                cout << "2. ���� �������������;" << endl;
                cout << "3. ���� ������." << endl;
                cout << "0. �����." << endl;
                cout << "1. ������� ����������." << endl;
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
            cout << "������������ ����, ���������!" << endl;
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
    cout << "���� �������������� - �������" << endl;
    do
    {
        try
        {
            cout << "1. �������� ������ ������;" << endl;
            cout << "2. �������� �������;" << endl;
            cout << "3. ������� ������ � �������;" << endl;
            cout << "4. �������� ������ �������;" << endl;
            cout << "5. ����� ������� �� ���;" << endl;
            cout << "6. �������� ���������� � �������� �������;" << endl;
            cout << "7. �������� ���������� � ������� �������� �������;" << endl;
            cout << "0. �����." << endl;
            cout << ">> ";
            cin >> choise;
            convertChoise = stoi(choise);
            stateConverte = true;
        }
        catch ( const std::exception& )
        {
            cout << "������������ ����, ���������!" << endl;
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
    cout << "���� �������������� - ������������" << endl;
    do
    {
        try
        {
            cout << "1. �������� ������ �������������;" << endl;
            cout << "2. �������� ������������;" << endl;
            cout << "3. ������� ������ � ������������;" << endl;
            cout << "4. �������� ������ ������������;" << endl;
            cout << "5. ����� ������������ �� ������;" << endl;
            cout << "0. �����." << endl;
            cout << ">> ";
            cin >> choise;
            convertChoise = stoi(choise);
            stateConverte = true;
        }
        catch ( const std::exception& )
        {
            cout << "������������ ����, ���������!" << endl;
            system("pause");
            system("CLS");
            stateConverte = false;
        }
    } while ( !stateConverte );

    return convertChoise;
}
