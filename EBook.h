#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook final : public Book {
private:
    double fileSize;

public: void printType() const override;
    EBook(std::string t, std::string a, std::string i, double s);

    void displayInfo() const override;

    std::string getExtraValue() const override { return std::to_string(fileSize);}
};

#endif