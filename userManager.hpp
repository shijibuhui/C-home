#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "UserClasses.hpp"
#include "UserFileManager.hpp"

Class UserManager 
{
    private:
        std::vector<User> users;
        UserFileManager userFileManager;
        
        void loadUsers();
    public:
        UserManager(std::string fileName);
        ~UserManager();

        void createUser(User* user);
        User* readUser(int account);
        void updateUser(int account,std::string newName,std::string newPassword);
        void deleteUser(int account);
        void displayAllUsers();
};

#endif