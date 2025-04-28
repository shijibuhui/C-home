#ifndef BOOK_HPP
#define BOOK_HPP 

#include <iostream>
#include <string>

class Book
{
    private:
        std::string bookName;
        std::string author;
        int ISBN;
        int number;
        std::string publisher;
        int price;
    public:
        Book(std::string bookName,std::string author,int ISBN,int number,std::string publisher,int price);
        void setBookName(std::string newBookName);
        std::string getBookName() const;
        void setAuthor(std::string newAuthor);
        std::string getAuthor() const;
        void setISBN(int newISBN);
        int getISBN() const;
        void setNumber(int newNumber);
        int getNumber() const;
        void setPrice(int newPrice);
        int getPrice() const;
        void setPublisher(std::string newPublisher);
        std::string getPublisher() const;
};

#endif