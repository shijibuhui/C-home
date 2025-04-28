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