#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "user.hpp"
#include "userFileManager.hpp"

// 用户管理类，负责用户信息的存储、读取和更新
class UserManager 
{
    private:
        // 存储用户信息的容器
        std::vector<User*> users;
        // 用户文件管理器，用于处理用户数据的文件读写
        UserFileManager fileManager;
        
        // 从文件中加载用户信息
        void loadUsers();

    public:
        // 构造函数，初始化用户管理器
        UserManager(std::string fileName);
        // 析构函数，释放用户管理器资源
        ~UserManager();

        // 创建新用户
        void createUser(User* user);
        // 根据账号读取用户信息
        User* readUser(long long int account);
        // 更新用户信息
        void updateUser(long long int account,std::string newName,std::string newPassword);
        // 删除用户
        void deleteUser(long long int account);
        // 显示所有用户信息
        void displayAllUsers();
};

#endif