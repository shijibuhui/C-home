#include <iostream>
#include "user.hpp"

//构造函数
User::User(const std::string& name,const std::string& password,long long int account) : name(name), password(password), account(account){}
Admin::Admin(const std::string& name,const std::string& password,long long int account) :User(name, password, account){}
Teacher::Teacher(const std::string& name,const std::string& password,long long int account) :User(name, password, account){}
Buyer::Buyer(const std::string& name,const std::string& password,long long int account) :User(name, password, account){}

void User::setName(const std::string& newName)
{
    name = newName;
}

std::string User::getName() const
{
    return name;
}

void User::setPassword(const std::string& newPassword)
{
    password = newPassword;
}

std::string User::getPassword() const
{
    return password;
}

void User::setAccount(long long int newAccount)
{
    account = newAccount;
}

long long int User::getAccount() const
{
    return account;
}

//家长类
Parents::Parents(const std::string& name,const std::string& password,long long int account, const std::string& kidName) : User(name,password,account),kidName(kidName){}

void Parents::setKidName(const std::string& newKidName)
{
    kidName = newKidName;
}

std::string Parents::getKidName() const
{
    return kidName;
}

void User::displayInfo() const
{
    std::cout << "姓名: " << name << ", 账号: " << account <<  ", 密码: " << password << std::endl;
}

void Parents::displayInfo() const
{
    User::displayInfo();
    std::cout << ", KidName: " << kidName << std::endl;
}


// 类Parents中的成员函数getType的实现
std::string Parents::getType() const
{
    // 返回类的类型标识字符串"家长"
    return "家长";
}


// 序列化Parents对象的信息为字符串
// 该函数将Parents对象中的账户信息、父母名称和孩子名称组合成一个字符串，便于传输或存储
// 返回值: 返回包含Parents对象信息的字符串，格式为"Parents:账户信息,父母名称,孩子名称"
std::string Parents::serialize() const
{
    return std::to_string(getAccount()) + "," + getName() + "," + getPassword() + "," + kidName;
}

void Teacher::displayInfo() const
{
    User::displayInfo();
}

std::string Teacher::getType() const
{
    return "教师";
}

std::string Teacher::serialize() const
{
    return std::to_string(getAccount()) + "," + getName() + "," + getPassword();
}

void Buyer::displayInfo() const
{
    User::displayInfo();
}

std::string Buyer::getType() const
{
    return "采购员";
}

std::string Buyer::serialize() const
{
    return std::to_string(getAccount()) + "," + getName() + "," + getPassword();
}

void Admin::displayInfo() const
{
    User::displayInfo();
}

std::string Admin::getType() const
{
    return "管理员";
}

std::string Admin::serialize() const
{
    return std::to_string(getAccount()) + "," + getName() + "," + getPassword();
}

std::string User::serialize() const
{
    return std::to_string(getAccount()) + "," + getName() + "," + getPassword();
}