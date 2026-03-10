#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book(std::string t = "Unknown", std::string a = "Unknown", std::string i = "000");
    Book(std::string t);

    ~Book();

    void borrowBook();
    void returnBook();
    void displayInfo();
};

#endif