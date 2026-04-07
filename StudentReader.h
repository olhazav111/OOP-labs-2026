#ifndef STUDENTREADER_H
#define STUDENTREADER_H

#include "Reader.h"

class StudentReader : public Reader {
private:
    std::string university;

public:
    StudentReader(std::string n, int i, int a, std::string u);

    void displayProfile () const override;
};

#endif