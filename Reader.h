#ifndef READER_H
#define READER_H

#include <iostream>
#include <string>


class Reader {
private:
    std::string name;
    int id;
    int age;

public:
    Reader(std::string n = "Unknown", int i = 0, int a = 0);
    Reader(std::string n);

    virtual ~Reader();

    virtual void displayProfile();
};

#endif