#include "stdafx.h"
#include "CSVParser.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>

#include <sql.h>
#include<sqltypes.h>
#include<sqlext.h>
#include "ODBC_Class.h"

using namespace std;

void CSVParser::InsertParsedDataToDb()
{
	SQLRETURN rc = SQL_SUCCESS;
	SQLWCHAR DBName[] = L"NotificationDB";
	SQLWCHAR SQLStmt[255] = {0};
	// Create An Instance Of The ODBC_Class Class
	ODBC_Class Example;
	// Connect To The Northwind Sample Database
	if (Example.ConHandle != NULL)
	{
		rc = SQLConnect(Example.ConHandle, DBName, SQL_NTS,
			(SQLWCHAR *) L"", SQL_NTS, (SQLWCHAR *) L"", SQL_NTS);
		// Allocate An SQL Statement Handle
		rc = SQLAllocHandle(SQL_HANDLE_STMT, Example.ConHandle,
				&Example.StmtHandle);
		if (rc == SQL_SUCCESS)
		{
			// Define A SELECT SQL Statement
			strcpy((char *) SQLStmt, "SELECT * FROM ItemDetails");
			// Prepare And Execute The SQL Statement
			rc = SQLExecDirect(Example.StmtHandle, SQLStmt, SQL_NTS);
			// Display The Results Of The SQL Query
			if (rc == SQL_SUCCESS)
			{
				Example.GetResultset();

				vector<vector<string>>::iterator it;
				for(it = Example.colData.begin(); it < Example.colData.end(); it++)
				{
					vector<string>::iterator iit;

					for(iit = it->begin(); iit < it->end(); iit++)
					{
						cout << "Printing table values" <<endl;
						cout<< *iit <<endl;
					}
					
				}
				// At this point you would want to do something
				// with the resultset, such as display it.
			}
		}
		// Free The SQL Statement Handle
		if (Example.StmtHandle != NULL)
			SQLFreeHandle(SQL_HANDLE_STMT, Example.StmtHandle);
		// Disconnect From The Northwind Sample Database
		rc = SQLDisconnect(Example.ConHandle);
	}
}

void CSVParser::ParseFile(string fileName)
{


	//\***************************
    cout << "Inside csvparser"<<endl;
    ifstream myfile(fileName, ios::in|ios::binary|ios::ate);
    string line;
    string item_array[3] = {"", "", ""};
    streampos size;
    char *memblock;
    if(myfile.is_open())
    {
        size = myfile.tellg();
        memblock = new char[size];
        myfile.seekg (0, ios::beg);
        myfile.read(memblock, size);
        myfile.close();
        int item_array_counter = 0;
        for(int i = 0; i < size; i++)
        {
                
                if(memblock[i]  != ',' && memblock[i]  != '\n'){
                 //   cout<<memblock[i];
                    item_array[item_array_counter].append(1, memblock[i]);
                }
                else{
                    item_array_counter++;
                if(item_array_counter >=3)
                {
					InsertParsedDataToDb();
                    for(int j = 0; j < 3; j++)
                    {
                        cout<<item_array[j]<<"\t";
                        item_array[j] = "";
                    }                    
                    cout<<endl;
                    item_array_counter = 0;
                    
                    
                }
                }
                
        }
        delete [] memblock;
        

        
    }
    else{
        cout<<"Unable to open file";
    }
}