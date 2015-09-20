#include "stdafx.h"
#include "Notifier.h"
#include "SubscriberAgent.h"
#include <vector>
#include <algorithm>
using namespace std;
void Notifier::Attach(SubscriberAgent *subscriber)
{
    list.push_back(subscriber);
}
void Notifier::Detach(SubscriberAgent *subscriber)
{    
    list.erase(std::remove(list.begin(), list.end(), subscriber), list.end());    
}

void Notifier::Notify()
{
    for(vector<SubscriberAgent*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Notify();
        }
    }
}