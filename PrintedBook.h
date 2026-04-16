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

    std::string getExtraValue() const override { return std::to_string(pages);}
};

#endif