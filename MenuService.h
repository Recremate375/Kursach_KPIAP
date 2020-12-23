#pragma once

#include "BaseMenu.h"
#include "BaseUserService.h"
#include "ClassSoldierBaseService.h"
#ifndef __MenuService__
#define __MenuService__

class MenuService
{
private:
    User* currentUser_;
    BaseUserService baseUS_;
    SoldierBaseService soldBS_;
    BaseMenu* menu_;
    bool Authorization();
    void SetMenu();
public:
    MenuService();
    ~MenuService();
    bool DisplayMenu();
};

#endif /* MenuService */