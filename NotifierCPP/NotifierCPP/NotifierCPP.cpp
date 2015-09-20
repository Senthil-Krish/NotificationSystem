// NotifierCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CSVParser.h"
#include "ItemHandler.h"
#include <stdio.h>
#include <iostream>
int _tmain(int argc, _TCHAR* argv[])
{
	ItemHandler *iH = new ItemHandler();
	iH->WatchFileAddition();
	char c;
	cin>>c;
	getchar();
    /*CSVParser *csvp = new CSVParser();
    csvp->ParseFile();
    getchar();*/
	return 0;
}

