#ifndef IPRINTABLE_H
#define IPRINTABLE_H

class IPrintable {
public:

    virtual void printDetails() const = 0; 
    

    virtual ~IPrintable() {} 
};

#endif