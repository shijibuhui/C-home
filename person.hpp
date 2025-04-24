#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person 
{
    private:
        std::string name;
        std::string account;
        std::string password;
    public:
        Person();
};

class Admin : public Person
{
    private:
        std::string name;
        std::string account;
        std::string password;
    public:
        Admin();
};

class Teacher : public Person
{
    private:
        std::string name;
        std::string account;
        std::string password;
    public:
        Teacher();
};

class Buyer : public Person
{
    private:
        std::string name;
        std::string account;
        std::string password;
    public:
        Buyer();
};

class Parents : public Person
{
    private:
        std::string name;
        std::string account;
        std::string password;
        std::string kidName;
    public:
        Parents();
};

#endif