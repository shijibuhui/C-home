#ifndef USER_HPP
#define USER_HPP

#include <string>

//用户基类，管理员、采购员、老师都使用此类
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
};

#endif