#include <iostream>
#include <string>
#include <windows.h>
#include "menu.hpp"
#include "UserManager.hpp"

void Menu::showMainMenu()
{
    std::cout << "===========教材采购管理系统============" << std::endl;
    std::cout << "1. 用户管理" << std::endl;
    std::cout << "2. 教材管理" << std::endl;
    std::cout << "3. 订单管理" << std::endl;
    std::cout << "4. 退出系统" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "请输入您的选择：";
}

void Menu::showUserMenu()
{
    std::cout << "===========用户管理菜单============" << std::endl;
    std::cout << "1. 添加用户" << std::endl;
    std::cout << "2. 查询用户" << std::endl;
    std::cout << "3. 修改用户" << std::endl;
    std::cout << "4. 删除用户" << std::endl;
    std::cout << "5. 显示所有用户" << std::endl;
    std::cout << "6. 返回主菜单" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "请输入您的选择：";
}

void Menu::showBookMenu()
{
    std::cout << "============教材管理菜单============" << std::endl;
    std::cout << "1. 添加教材" << std::endl;
    std::cout << "2. 查询教材" << std::endl;
    std::cout << "3. 修改教材" << std::endl;
    std::cout << "4. 删除教材" << std::endl;
    std::cout << "5. 显示所有教材" << std::endl;
    std::cout << "6. 返回主菜单" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "请输入您的选择：";
}

void Menu::showBuyMenu()
{
    std::cout << "============购买管理菜单============" << std::endl;
    std::cout << "1. 购买教材" << std::endl;
    std::cout << "2. 退订教材" << std::endl;
    std::cout << "3. 查询购买记录" << std::endl;
    std::cout << "4. 返回主菜单" << std::endl;
    std::cout << "===================================" << std::endl;
}

void Menu::showBuyerBookMenu()
{
    std::cout << "============采购员管理菜单============" << std::endl;
    std::cout << "1. 添加采购教材" << std::endl;
    std::cout << "2. 删除采购教材" << std::endl;
    std::cout << "3. 修改采购教材" << std::endl;
    std::cout << "4. 显示所有采购教材" << std::endl;
    std::cout << "5. 更新教材状态" << std::endl;
    std::cout << "5. 返回主菜单" << std::endl;

}

void userManagementSystem(UserManager& manager)   //用户管理界面
{
    Menu menu;

    int choice;
    long long int account;
    std::string name,password,kidName;

    do
    {
        system("cls");
        menu.showUserMenu();
        std::cin >> choice;

        switch (choice)
        {
            case 1:   //输入1为添加用户
                std::cout << "请输入账号：";
                std::cin >> account;
                std::cout << "请输入用户名：";
                std::cin >> name;
                std::cout << "请输入密码：";
                std::cin >> password;
                int userType;  //用户类型在此处定义
                std::cout << "选择用户类型（1.管理员,2.采购员,3.老师,4.家长）：" << std::endl;
                std::cin >> userType;
                User* newUser;
                if(userType == 4)
                {
                    std::cout << "请输入孩子姓名：";
                    std::cin >> kidName;
                    newUser = new Parents(name,password,account,kidName);
                }
                else if(userType == 1)
                {
                    newUser = new Admin(name,password,account);
                }
                else if(userType == 2)
                {
                    newUser = new Buyer(name,password,account);
                }
                else if(userType == 3)
                {
                    newUser = new Teacher(name,password,account);
                }
                else
                {
                    std::cout << "无效的用户类型！" << std::endl;
                }
                manager.createUser(newUser);
                break;
            case 2:   //输入2为查询用户
            {
                std::cout << "请输入用户账号：" << std::endl;
                std::cin >> account;
                User* user = manager.readUser(account);
                if(user)
                {
                    user->displayInfo();
                }
                else
                {
                    std::cout << "用户不存在！" << std::endl;
                }
                std::cout << "按任意键返回上级菜单..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 3:   //输入3为修改用户
            {
                std::cout << "请输入要修改的用户账号：" << std::endl;
                std::cin >> account;
                std::cout << "请输入新的用户名：" << std::endl;
                std::cin >> name;
                std::cout << "请输入新的密码：" << std::endl;
                std::cin >> password;
                manager.updateUser(account,name,password);
                break;
            }
            case 4:   //  输入4为删除用户
            {
                std::cout << "请输入要删除的用户账号：" << std::endl;
                std::cin >> account;
                manager.deleteUser(account);
                break;
            }
            case 5:   //  输入5为查看所有用户信息
            {
                manager.displayAllUsers();
                std::cout << "按任意键返回上级菜单..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                system("cls");
                break;
            }
            case 6:   //  输入6为返回上级菜单
            {
                std::cout << "返回上级菜单..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                system("cls");
                break;
            }
            default:std::cout << "输入错误！请重新输入..." << std::endl;  //排除其他情况
        }
    }
    while (choice != 6);
}
