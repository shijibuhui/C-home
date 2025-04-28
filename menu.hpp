#ifndef MENU_HPP
#define MENU_HPP

#include "UserManager.hpp"

class Menu
{
    public:
        void showMainMenu();
        void showUserMenu();
        void showBookMenu();
        void showBuyMenu();
        void showBuyerBookMenu();
};

void userManagementSystem(UserManager& manager);

#endif