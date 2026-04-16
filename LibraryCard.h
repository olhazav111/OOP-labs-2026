#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H

#include <iostream>
#include <string>
#include "Reader.h"
#include <memory>

class LibraryCard {
private:
    int cardNumber;
    std::string date;
    bool active;
    std::shared_ptr<Reader> owner;

public:
    LibraryCard(int num = 0, std::string d = "01.01.2024", std::shared_ptr<Reader> r = nullptr);

    ~LibraryCard();

    void displayInfo();
};

#endif