#include "Book.h"

Book::Book(std::string t, std::string a, std::string i)
        : title(t), author(a), isbn(i), available(true)
{
    std::cout << "Book created: " << title << std::endl;
}

Book::Book(std::string t) : Book(t, "Unknown", "000") {}

Book::~Book()
{
    std::cout << "Book deleted: " << title << std::endl;
}

void Book::borrowBook()
{
    available = false;
}

void Book::returnBook()
{
    available = true;
}

void Book::displayInfo()
{
    std::cout << "Book: " << title
              << " | Author: " << author
              << " | Available: " << (available ? "Yes" : "No")
              << std::endl;
}