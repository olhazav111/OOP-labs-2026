#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H

#include <iostream>
#include <string>
#include "Reader.h"

class LibraryCard {
private:
    int cardNumber;
    std::string date;
    bool active;

    Reader owner;

public:
    LibraryCard(int num = 0, std::string d = "01.01.2024", Reader r = Reader());

    ~LibraryCard();

    void displayInfo();
};

#endif