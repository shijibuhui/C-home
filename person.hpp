#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class User
{
    private:
        std::string name;
        int account;
        std::string password;
    public:
        User(const std::string& name,const std::string& password, int account);
        void setName(const std::string& newName);
        std::string getName() const;
        void setPassword(const std::string& newPassword);
        std::string  getPassword() const;
        void setAccount(int newAccount);
        int getAccount() const;
};

class Admin : public User
{
    private:
        std::string name;
        int account;
        std::string password;
    public:
        Admin();
};

class Teacher : public User
{
    private:
        std::string name;
        int account;
        std::string password;
    public:
        Teacher();
};

class Buyer : public User
{
    private:
        std::string name;
        int account;
        std::string password;
    public:
        Buyer();
};

class Parents : public User
{
    private:
        std::string name;
        int account;
        std::string password;
        std::string kidName;
    public:
        Parents();
};

#endif