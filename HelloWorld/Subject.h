#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <Store.h>
class Subject
{
    
    std::vector<Store*> list;
public:
    void Attach(Store *product);
    void Detach(Store *product);
    void Notify(float price); 
    
};

#endif // SUBJECT_H
