#include "Subject.h"
#include <vector>
#include <algorithm>
using namespace std;
void Subject::Attach(Store *store)
{
    list.push_back(store);
}
void Subject::Detach(Store *store)
{    
    list.erase(std::remove(list.begin(), list.end(), store), list.end());    
}

void Subject::Notify(float price)
{
    for(vector<Store*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Update(price);
        }
    }
}

