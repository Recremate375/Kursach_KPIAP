#pragma once
#include "BaseMenu.h"

class AdminMenu : virtual public BaseMenu
{
private:

public:
    AdminMenu();
    int DisplayMenu(int lchoise);
    int DisplaySoldierMenu();
    int DisplayUserMenu();
    ~AdminMenu();
};

