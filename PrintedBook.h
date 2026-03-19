#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"

class PrintedBook : public Book {
private:
    int pages;

public:
    PrintedBook(std::string t, std::string a, std::string i, int p);

    void displayInfo();
};

#endif