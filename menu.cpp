#include <iostream>
#include <string>
#include "menu.hpp"

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
    std::cout << "2. 删除用户" << std::endl;
    std::cout << "3. 修改用户" << std::endl;
    std::cout << "4. 查询用户" << std::endl;
    std::cout << "5. 显示所有用户" << std::endl;
    std::cout << "6. 返回主菜单" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "请输入您的选择：";
}

void Menu::showBookMenu()
{
    std::cout << "============教材管理菜单============" << std::endl;
    std::cout << "1. 添加教材" << std::endl;
    std::cout << "2. 删除教材" << std::endl;
    std::cout << "3. 修改教材" << std::endl;
    std::cout << "4. 查询教材" << std::endl;
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