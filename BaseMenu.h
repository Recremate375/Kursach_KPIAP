#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class BaseMenu
{
public:
    BaseMenu();
    ~BaseMenu();
    virtual int DisplayMenu(int lchoise) = 0;
};

