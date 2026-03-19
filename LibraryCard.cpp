#include "LibraryCard.h"

LibraryCard::LibraryCard(int num, std::string d, Reader r)
        : cardNumber(num), date(d), active(true), owner(r)
{
    std::cout << "Card created: " << cardNumber << std::endl;
}

LibraryCard::~LibraryCard()
{
    std::cout << "Card deleted: " << cardNumber << std::endl;
}

void LibraryCard::displayInfo()
{
    std::cout << "Card: " << cardNumber
              << " | Active: "
              << (active ? "Yes" : "No")
              << std::endl;

    owner.displayProfile();
}