#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H

#include <iostream>
#include <string>

class LibraryCard {
private:
    int cardNumber;
    std::string date;
    bool active;

public:
    LibraryCard(int num = 0, std::string d = "01.01.2024");

    ~LibraryCard();

    void displayInfo();
};

#endif