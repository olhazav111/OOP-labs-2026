#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook final : public Book {
private:
    double fileSize;

public:
    EBook(std::string t, std::string a, std::string i, double s);

    void displayInfo() const override;
};

#endif