#include "EBook.h"

#include <iostream>

EBook::EBook(std::string t, std::string a, std::string i, double s)
        : Book(t,a,i), fileSize(s)
{
    std::cout << "EBook created\n";
}

void EBook::displayInfo() const
{
    Book::displayInfo();
    std::cout << "File size: " << fileSize << " MB\n";
}

void EBook::printType() const {
    std::cout << "Electronic Book (EBook)" << std::endl;
}