#include <iostream>
#include <string>
#include "book.hpp"

Book::Book(std::string bookName,std::string author,int ISBN,int number,std::string publisher,int price) : bookName(bookName),author(author),ISBN(ISBN),number(number),publisher(publisher),price(price){}

void Book::setBookName(std::string newBookName)
{
    bookName = newBookName;
}

std::string Book::getBookName() const
{
    return bookName;
}

void Book::setAuthor(std::string newAuthor)
{
    author = newAuthor;
}

std::string Book::getAuthor() const
{
    return author;
}

void Book::setISBN(int newISBN)
{
    ISBN = newISBN;
}

int Book::getISBN() const
{
    return ISBN;
}

void Book::setNumber(int newNumber)
{
    number = newNumber;
}

int Book::getNumber() const
{
    return number;
}

void Book::setPrice(int newPrice)
{
    price = newPrice;
}

int Book::getPrice() const
{
    return price;
}

void Book::setPublisher(std::string newPublisher)
{
    publisher = newPublisher;
}

std::string Book::getPublisher() const
{
    return publisher;
}

void Book::display() const
{
    std::cout << "书名: " << bookName << ", 作者: " << author <<  ", ISBN编号: " << ISBN << std::endl << ",出版社：" << publisher;
}

std::string Book::serialize() const   //存储格式
{
    return bookName + "," + author + "," + std::to_string(ISBN) + "," + std::to_string(number) + "," + publisher + "," + std::to_string(price);
}