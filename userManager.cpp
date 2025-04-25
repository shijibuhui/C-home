#include "UserManager.hpp"

UserManager::UserManager(const std::string filename)
    : fileManager(filename)
{
    this->loadUsers();
}

UserManager::~UserManager()
{
    for(User* user : users)
    {
        delete user;
    }
    users.clear();
}

void UserManager::createUser(User* user)
{
    users.push_back(user);
    fileManager.saveUsers(users);
}

User* UserManager::readUser(long long int newAccount)
{
    for(User* user : users)
    {
        if(user->getAccount() == newAccount)
        {
            return user;
        }
    }
    return nullptr;
}

void UserManager::updateUser(long long int newAccount,std::string newName,std::string newPassword)
{
    for(User* user : users)
    {
        if(user->getAccount() == newAccount)
        {
            user->setName(newName);
            user->setPassword(newPassword);
            fileManager.saveUsers(users);
            return;
        }
    }
    std::cout << "User with ID" << account << "does not exist!" << std::endl;
}

void UserManager::deleteUser(long long int account)
{
    for(auto it = users.begin(); it != users.end(); ++it)
    {
        if((*it)->getAccount() == account)
        {
            delete *it;
            users.erase(it);
            fileManager.saveUsers(users);
            return;
        }
    std::cerr << "User with ID" << account << "does not exist!" << std::endl;
    }
}

void UserManger::displayUsers()
{
    for(User* user : users)
    {
        user->displayInfo();
    }
}

void UserManager::loadUsers()
{
    users = fileManager.loadUsers();
}