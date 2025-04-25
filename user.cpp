#include <iostream>
#include "user.hpp"

//构造函数
User::User(const std::string& name,const std::string& password,long long int account) :account(account),name(name),password(password){}

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
