#ifndef PRODUCT_H
#define PRODUCT_H

#include "Subject.h"

class Product : public Subject
{
public:
    void ChangePrice(float price);
};

#endif // PRODUCT_H
