#include "Main.h"

int main(int argc, char* argv[])
{
    MenuService* menuService = new MenuService();

    while ( menuService->DisplayMenu() );

    return 0;
}
