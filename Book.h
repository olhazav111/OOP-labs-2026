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

    static int bookCount;

public:
    Book(std::string t = "Unknown", std::string a = "Unknown", std::string i = "000");
    Book(std::string t);

    Book(const Book& other);
    Book(Book&& other);

    ~Book();

    void borrowBook();
    void returnBook();
    void displayInfo() const;

    static int getBookCount();

    bool operator!();
    bool operator==(const Book& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);
};

#endif