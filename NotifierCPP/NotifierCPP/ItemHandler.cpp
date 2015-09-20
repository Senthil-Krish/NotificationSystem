#include "stdafx.h"
#include "ItemHandler.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include "CSVParser.h"
using namespace std;
string sharedDir= "C:\\Users\\srisai\\Desktop\\SharedFolder\\";
wchar_t sharedDirDummy[200] = L"C:\\Users\\srisai\\Desktop\\SharedFolder\\";
void ProcessFile()
{
	/*char *cFileName = new char[wcslen(sharedDir)];
	int len = wcslen(sharedDir);
	memcpy(cFileName, sharedDir, wcslen(sharedDir));
	string fileName(cFileName);
	fileName += "\\*.csv";*/
	//wchar_t *filePathWild = new wchar_t(wcslen(sharedDir));
	//memcpy(filePathWild, sharedDir,sizeof(wchar_t) * wcslen(sharedDir));
	//filePathWild[37] = '\0';
	wchar_t *ext = L"*.csv";
	wcscat(sharedDirDummy, ext);
	CSVParser parser;

	WIN32_FIND_DATA FindFileData;
   HANDLE hFind;

   wchar_t *fileName;

   hFind = FindFirstFile(sharedDirDummy, &FindFileData);
   if (hFind == INVALID_HANDLE_VALUE) 
   {
      printf ("FindFirstFile failed (%d)\n", GetLastError());
      return;
   } 
   else 
   {
	   fileName = FindFileData.cFileName;
      _tprintf (TEXT("The first file found is %s\n"), 
                FindFileData.cFileName);
      FindClose(hFind);
   }

  //  wchar_t *fileNameWithExt = sharedDir;
	//wstring ws(sharedDir);
	//string fName(ws.begin(), ws.end());

	wstring wse(fileName);
	string fExt(wse.begin(), wse.end());
	sharedDir += fExt;
//	wcscat(fileNameWithExt, fileName);

	parser.ParseFile(sharedDir);
}

void WatchDirectory(wchar_t *lpDir)
{
   DWORD dwWaitStatus; 
   HANDLE dwChangeHandles[2]; 
   TCHAR lpDrive[4];
   TCHAR lpFile[_MAX_FNAME];
   TCHAR lpExt[_MAX_EXT];

   //_tsplitpath_s(lpDir, lpDrive, 4, NULL, 0, lpFile, _MAX_FNAME, lpExt, _MAX_EXT);
  // wchar_t *wcLpDir = (wchar_t*) &lpDir;
   _tsplitpath_s(lpDir, lpDrive, 4, NULL, 0, lpFile, _MAX_FNAME, lpExt, _MAX_EXT);

   lpDrive[2] = (TCHAR)'\\';
   lpDrive[3] = (TCHAR)'\0';
 
// Watch the directory for file creation and deletion. 
	LPCWSTR wDir = (LPCWSTR) lpDir;
   dwChangeHandles[0] = FindFirstChangeNotification( 
      wDir,                         // directory to watch 
      FALSE,                         // do not watch subtree 
      FILE_NOTIFY_CHANGE_FILE_NAME); // watch file name changes 
 
   if (dwChangeHandles[0] == INVALID_HANDLE_VALUE) 
   {
     printf("\n ERROR: FindFirstChangeNotification function failed.\n");
     ExitProcess(GetLastError()); 
   }


// Watch the subtree for directory creation and deletion. 
 
   dwChangeHandles[1] = FindFirstChangeNotification( 
      lpDrive,                       // directory to watch 
      TRUE,                          // watch the subtree 
      FILE_NOTIFY_CHANGE_DIR_NAME);  // watch dir name changes 
 
   if (dwChangeHandles[1] == INVALID_HANDLE_VALUE) 
   {
     printf("\n ERROR: FindFirstChangeNotification function failed.\n");
     ExitProcess(GetLastError()); 
   }
 

// Make a final validation check on our handles.

   if ((dwChangeHandles[0] == NULL) || (dwChangeHandles[1] == NULL))
   {
     printf("\n ERROR: Unexpected NULL from FindFirstChangeNotification.\n");
     ExitProcess(GetLastError()); 
   }

// Change notification is set. Now wait on both notification 
// handles and refresh accordingly. d
 
   while (TRUE) 
   { 
   // Wait for notification.
 
      printf("\nWaiting for notification...\n");

      dwWaitStatus = WaitForMultipleObjects(2, dwChangeHandles, 
         FALSE, INFINITE); 
 
      switch (dwWaitStatus) 
      { 
         case WAIT_OBJECT_0: 
 
         // A file was created, renamed, or deleted in the directory.
         // Refresh this directory and restart the notification.
			 cout << "A file was created or renamed or deleted" << endl;
 //            RefreshDirectory(lpDir); 
             if ( FindNextChangeNotification(dwChangeHandles[0]) == FALSE )
             {
               printf("\n ERROR: FindNextChangeNotification function failed.\n");
               ExitProcess(GetLastError()); 
             }

			 ProcessFile();

             break; 
 
         //case WAIT_OBJECT_0 + 1: 
 
         //// A directory was created, renamed, or deleted.
         //// Refresh the tree and restart the notification.
 
         //    RefreshTree(lpDrive); 
         //    if (FindNextChangeNotification(dwChangeHandles[1]) == FALSE )
         //    {
         //      printf("\n ERROR: FindNextChangeNotification function failed.\n");
         //      ExitProcess(GetLastError()); 
         //    }
         //    break; 
 
         case WAIT_TIMEOUT:

         // A timeout occurred, this would happen if some value other 
         // than INFINITE is used in the Wait call and no changes occur.
         // In a single-threaded environment you might not want an
         // INFINITE wait.
 
            printf("\nNo changes in the timeout period.\n");
            break;

         default: 
            printf("\n ERROR: Unhandled dwWaitStatus.\n");
            ExitProcess(GetLastError());
            break;
      }
   }
}

void ItemHandler::WatchFileAddition()
{
	WatchDirectory(sharedDirDummy);
}

void ItemHandler::CheckAndAddItem(ItemStruct item)
{
    // Database query to check and update or add new item here

}