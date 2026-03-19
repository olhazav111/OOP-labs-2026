#include "PrintedBook.h"

PrintedBook::PrintedBook(std::string t, std::string a, std::string i, int p)
        : Book(t,a,i), pages(p)
{
    std::cout << "PrintedBook created\n";
}

void PrintedBook::displayInfo()
{
    Book::displayInfo();
    std::cout << "Pages: " << pages << std::endl;
}