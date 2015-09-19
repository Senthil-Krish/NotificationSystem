#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include "Observer.h"

class Store : Observer
{
    //Name of the Shop
    std::string name;
    float price;
public:
    Store(std::string n); 
    void Update(float price);          
};

#endif // STORE_H
