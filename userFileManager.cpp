#include "userFileManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// 用户文件管理类构造函数
// 参数: filename - 用户数据文件的路径
UserFileManager::UserFileManager(const std::string& filename) : filename(filename) {}

// 从文件中加载用户信息
// 返回值: std::vector<User*> - 加载的用户信息列表
std::vector<User*> UserFileManager::loadUsers() 
{
    std::vector<User*> users;
    std::ifstream file(filename);
    if(file.is_open())
    {
        std::string line;
        while(std::getline(file, line))
        {
            // 解析用户类型
            size_t pos = line.find(",");     // 查找字符串中的逗号位置，用于后续分割字符串
            std::string type = line.substr(0, pos);      // 提取逗号前的字符串作为类型信息
            line = line.substr(pos + 1);       // 更新原始字符串，保留逗号后的部分，以备下一次处理

            // 解析用户账号
            pos = line.find(",");
            long long int account = std::stoll(line.substr(0, pos));  // 使用std::stoll函数将line字符串的子串转换为长整型
            line = line.substr(pos + 1);

            // 解析用户名
            pos = line.find(",");
            std::string name = line.substr(0, pos);
            line = line.substr(pos + 1);

            // 解析用户密码
            pos = line.find(",");
            std::string password = line.substr(0, pos);

            // 根据用户类型创建用户对象
            if(type == "Parents")
            {
                std::string kidName = line.substr(pos + 1);// 提取pos位置之后的子字符串作为孩子的名字
                // 创建Parents对象并添加到users容器中
                // Parents构造函数的参数包括账户、名称、密码和孩子名字
                users.push_back(new Parents(account, name, password, kidName));
            }
            else(type == "User")
            {
                users.push_back(new User(account, name, password));
            }
        }
        file.close();
    }
    else
    {
        std::cout << "读取文件失败！" << filename << std::endl;
    }
    return users;
}

// 将用户信息保存到文件
// 参数: users - 待保存的用户信息列表
void UserFileManager::saveUsers(const std::vector<User*>& users) 
{
    std::ofstream file(filename);  // 尝试打开指定的文件以写入用户信息
    if(file.is_open())  //如果文件打开成功
    {
        for(const auto& user : users)// 遍历用户集合，将每个用户的信息写入文件
        {
            file << user->getType() << "," << user->serialize() << std::endl;  // 将用户信息序列化后写入文件
        }
        // 关闭文件
        file.close();
    }
    else
    {
        std::cout << "写入文件失败！" << filename << std::endl;   // 如果文件打开失败，则输出错误信息
    }
}