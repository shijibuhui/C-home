#include <iostream>
#include "UserManager.hpp"
#include "UserFileManager.hpp"

// UserManager类的构造函数，初始化fileManager并加载用户数据
UserManager::UserManager(const std::string fileName)
    : fileManager(fileName)
{
    this->loadUsers();
}

// UserManager类的析构函数，释放动态分配的用户对象内存
UserManager::~UserManager()
{
    for(User* user : users)
    {
        delete user;
    }
    users.clear();
}

// 创建用户并保存到文件中
void UserManager::createUser(User* user)
{
    users.push_back(user);
    fileManager.saveUsers(users);  //保存用户数据到文件
}

// 根据账号读取用户信息，如果找到则返回用户指针，否则返回nullptr
User* UserManager::readUser(long long int account)
{
    for(User* user : users)
    {
        if(user->getAccount() == account)
        {
            return user;
        }
    }
    return nullptr;
}

// 更新用户信息，包括用户名和密码，如果用户存在则更新并保存，否则输出错误信息
void UserManager::updateUser(long long int account,std::string newName,std::string newPassword)
{
    for(User* user : users)  // 遍历用户列表
    {
        if(user->getAccount() == account)// 检查用户的账户是否已经存在
        {
            // 更新用户的名称和密码
            user->setName(newName);
            user->setPassword(newPassword);
            
            // 保存更新后的用户信息到文件
            fileManager.saveUsers(users);
            
            // 更新完成，结束函数执行
            return;
        }
    }
    std::cout << "账号：" << account << "该账户不存在！" << std::endl;  
}

// 删除用户，如果用户存在则删除并保存更新，否则输出错误信息
void UserManager::deleteUser(long long int account)
{
        // 遍历用户集合，寻找并删除指定账户
    for(auto it = users.begin(); it != users.end(); ++it)
    {
        // 检查当前用户的账户是否与指定账户匹配
        if((*it)->getAccount() == account)
        {
            // 删除用户对象并从集合中移除
            delete *it;
            users.erase(it);
    
            // 更新用户数据到文件
            fileManager.saveUsers(users);
            return;
        }
    }
    std::cerr << "账号：" << account << "该账号不存在！" << std::endl;
}

// 显示所有用户的信息
void UserManager::displayAllUsers()
{
    for(User* user : users)
    {
        user->displayInfo();
    }
}

// 加载用户信息，从文件中读取用户数据并更新到内存中
void UserManager::loadUsers()
{
    users = fileManager.loadUsers();
}