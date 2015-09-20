#ifndef ITEMHANDLER_H
#define ITEMHANDLER_H
#include "Notifier.h"
#include <string>


using namespace std;
struct ItemStruct{
int itemNumber;
string attributeName;
string attributeValue;    
};

class ItemHandler : Notifier
{
public:
    void CheckAndAddItem(ItemStruct item);
	void WatchFileAddition();
	
};

#endif // ITEMHANDLER_H
