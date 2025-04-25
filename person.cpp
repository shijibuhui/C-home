#include <iostream>
#include "person.hpp"

//构造函数
User::User(const std::string& name,const std::string& password, int account) :account(account),name(name),password(password){}

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

void User::setAccount(int newAccount)
{
    account = newAccount;
}

int User::getAccount() const
{
    return account;
}