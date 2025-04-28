#include <iostream>
#include "user.hpp"
#include "UserManager.hpp"
#include "userFileManager.hpp"
#include "menu.hpp"
#include "book.hpp"

int main()
{
    UserManager manager("users.txt");
    Menu menu;
    int choice = 0;
    menu.showMainMenu();
    std::cin >> choice;
    switch(choice)
    {
        case 1:
        {
            userManagementSystem(manager);
            break;
        }
        case 2:
        {
            std::cout << "教材管理界面" << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "订单管理界面" << std::endl;
            break;
        }
        case 4:
        {
            break;
        }
    }

    return 0;
}