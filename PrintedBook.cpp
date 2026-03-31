#include "PrintedBook.h"
#include <iostream>

PrintedBook::PrintedBook(std::string t, std::string a, std::string i, int p)
        : Book(t,a,i), pages(p)
{
    std::cout << "PrintedBook created\n";
}

void PrintedBook::displayInfo() const
{
    Book::displayInfo();
    std::cout << "Pages: " << pages << std::endl;
}

void PrintedBook::printType() const
{
    std::cout << "Printed book\n";
}