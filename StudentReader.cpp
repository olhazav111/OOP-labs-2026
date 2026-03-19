#include "StudentReader.h"

StudentReader::StudentReader(std::string n, int i, int a, std::string u)
        : Reader(n,i,a), university(u)
{
    std::cout << "StudentReader created\n";
}

void StudentReader::displayProfile()
{
    Reader::displayProfile();
    std::cout << "University: " << university << std::endl;
}