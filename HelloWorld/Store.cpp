#include "Store.h"


Store::Store(std::string name)
{
    this->name = name;
}

void Store::Update(float price)
{
    this->price = price;

    //Lets print on console just to test the working
    std::cout << "Price at "<< name << " is now "<< price << "\n";
}


