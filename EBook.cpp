#include "EBook.h"

EBook::EBook(std::string t, std::string a, std::string i, double s)
        : Book(t,a,i), fileSize(s)
{
    std::cout << "EBook created\n";
}

void EBook::displayInfo()
{
    Book::displayInfo();
    std::cout << "File size: " << fileSize << " MB\n";
}