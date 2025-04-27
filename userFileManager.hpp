#ifndef USERFILEMANAGER_HPP
#define USERFILEMANAGER_HPP

#include <iostream>
#include <vector>
#include "user.hpp"

// 定义UserFileManager类，用于管理用户文件
class UserFileManager 
{
    private:
        // 存储文件名
        std::string filename;
    public:
        // 构造函数，初始化文件名
        UserFileManager(const std::string& filename) : filename(filename) {}
        
        // 从文件中加载用户数据

        std::vector<User*> loadUsers();
        
        //将用户数据保存到文件中
        void saveUsers(std::vector<User*>& users);
};

#endif