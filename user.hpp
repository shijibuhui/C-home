#ifndef USER_HPP
#define USER_HPP

#include <string>

//用户基类
class User
{
    private:
        std::string name;
        long long int account;
        std::string password;
    public:
        User(const std::string& name,const std::string& password, long long int account);
        void setName(const std::string& newName);
        std::string getName() const;
        void setPassword(const std::string& newPassword);
        std::string  getPassword() const;
        void setAccount(long long int newAccount);
        long long int getAccount() const;

        void displayInfo() const;
        virtual std::string getType() const = 0;
        virtual std::string serialize() const;
};

//家长类
class Parents : public User
{
    private:
        std::string kidName;
    public:
        Parents(const std::string& name,const std::string& password, long long int account, const std::string& kidName);
        void setKidName(const std::string& newKidName);
        std::string getKidName() const;

        void displayInfo() const;
        std::string getType() const override;
        std::string serialize() const override;
};

class Teacher : public User
{
    public:
        Teacher(const std::string& name,const std::string& password, long long int account);
        void displayInfo() const;
        std::string getType() const override;
        std::string serialize() const override;
};

class Buyer : public User
{
    public:
        Buyer(const std::string& name,const std::string& password, long long int account);
        void displayInfo() const;
        std::string getType() const override;
        std::string serialize() const override;
};

class Admin : public User
{
    public:
        Admin(const std::string& name,const std::string& password, long long int account);
        void displayInfo() const;
        std::string getType() const override;
        std::string serialize() const override;
};

#endif