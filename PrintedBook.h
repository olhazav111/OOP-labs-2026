#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"

class PrintedBook final : public Book {
private:
    int pages;

public:
    PrintedBook(std::string t, std::string a, std::string i, int p);

    void displayInfo() const override;
    void printType() const override;
};

#endif