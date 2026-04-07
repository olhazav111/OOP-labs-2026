#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "IPrintable.h"

class Book : public IPrintable {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

    static int bookCount;

public:
    Book(std::string t = "Unknown", std::string a = "Unknown", std::string i = "000");
    Book(std::string t);

    Book(const Book& other);
    Book(Book&& other);

    virtual ~Book();

    void borrowBook();
    void returnBook();
    virtual void displayInfo() const;

    virtual void printType() const = 0;

    void printDetails() const override;

    static int getBookCount();

    bool operator!() const;

    bool operator==(const Book& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);
};

#endif