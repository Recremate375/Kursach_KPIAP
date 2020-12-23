#pragma once

#include "BaseMenu.h"

class Menu : virtual public BaseMenu
{
private:
    string locale;
public:
    Menu();
    ~Menu();
    int DisplayMenu(int lchoise);
    bool SetConsoleLocale();
};
