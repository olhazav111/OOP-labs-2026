#include "Reader.h"

Reader::Reader(std::string n, int i, int a)
        : name(n), id(i), age(a)
{
    std::cout << "Reader created: " << name << std::endl;
}

Reader::Reader(std::string n) : Reader(n, 0, 0) {}

Reader::~Reader()
{
    std::cout << "Reader deleted: " << name << std::endl;
}

void Reader::displayProfile()
{
    std::cout << "Name: " << name
              << " | ID: " << id
              << " | Age: " << age
              << std::endl;
}