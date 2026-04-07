#ifndef READER_H
#define READER_H

#include <string>
#include <iostream>
#include "IPrintable.h"

class Reader : public IPrintable {
private:
    std::string name;
    int id;
    int age;

public: void printDetails() const override;
    Reader(std::string n = "Unknown", int i = 0, int a = 0);
    Reader(std::string n);

    virtual ~Reader();

    virtual void displayProfile() const;
};

#endif