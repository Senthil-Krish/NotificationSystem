#ifndef NOTIFIER_H
#define NOTIFIER_H
#include <vector>
#include "SubscriberAgent.h"
class Notifier
{
    std::vector<SubscriberAgent*> list;
public:
    void Attach(SubscriberAgent *subscriber);
    void Detach(SubscriberAgent *subscriber);
    void Notify(); 
};

#endif // NOTIFIER_H
