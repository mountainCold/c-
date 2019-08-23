#pragma once
#include "Data.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

/************************************
* Method:    MessageListener
* FullName:  MessageListener
* Access:    public 
* Returns:   int
* Qualifier:
* Parameter: int x
************************************/
int MessageListener(int x = 0);
/************************************
* Method:    KeyListener
* FullName:  KeyListener
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: char & ch1
* Parameter: char & ch2
* Parameter: char & bch1
* Parameter: char & bch2
************************************/
void KeyListener(char& ch1, char& ch2, char& bch1, char& bch2);
/************************************
* Method:    KeydListener
* FullName:  KeydListener
* Access:    public 
* Returns:   int
* Qualifier:
************************************/
int KeyListener();
/************************************
* Method:    ShowCuror
* FullName:  ShowCuror
* Access:    public 
* Returns:   void
* Qualifier:
************************************/
void ShowCuror();
/************************************
* Method:    WriteChar
* FullName:  WriteChar
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: int x
* Parameter: int y
* Parameter: int heath
* Parameter: WORD color
************************************/
void WriteChar(int x, int y, int heath, WORD color = 7);
/************************************
* Method:    WriteChar
* FullName:  WriteChar
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: int x
* Parameter: int y
* Parameter: const char * str
* Parameter: WORD color
************************************/
void WriteChar(int x, int y, const char* str, WORD color = 7);
/************************************
* Method:    WriteTank
* FullName:  WriteTank
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: int x
* Parameter: int y
* Parameter: int color
************************************/
void WriteTank(int x, int y, int color);
/************************************
* Method:    DwFrame
* FullName:  DwFrame
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: int x1
* Parameter: int x2
* Parameter: int y1
* Parameter: int y2
* Parameter: int n
************************************/
void DwFrame(int x1, int x2, int y1, int y2, int n);
/************************************
* Method:    WriteFood
* FullName:  WriteFood
* Access:    public 
* Returns:   int
* Qualifier:
* Parameter: int x
* Parameter: int y
************************************/
int WriteFood(int x, int y);
/************************************
* Method:    EditMap
* FullName:  EditMap
* Access:    public 
* Returns:   void
* Qualifier:
************************************/
/*
void EditMap();
/ ************************************
* Method:    MapManage
* FullName:  MapManage
* Access:    public 
* Returns:   void
* Qualifier:
************************************ /
void MapManage();
/ ************************************
* Method:    RecordManage
* FullName:  RecordManage
* Access:    public 
* Returns:   bool
* Qualifier:
************************************ /
bool RecordManage();
*/
/************************************
* Method:    ReadMap
* FullName:  ReadMap
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: char * mName
************************************/

void ReadMap(char* mName);/*
/ ************************************
* Method:    SaveMap
* FullName:  SaveMap
* Access:    public 
* Returns:   void
* Qualifier:
************************************ /
void SaveMap();
/ ************************************
* Method:    ReadRecord
* FullName:  ReadRecord
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: char * mName 
************************************ /

void ReadRecord(char* mName);
/ ************************************
* Method:    SaveRecord
* FullName:  SaveRecord
* Access:    public 
* Returns:   void
* Qualifier:
************************************ /
void SaveRecord();
/ ************************************
* Method:    SaveName
* FullName:  SaveName
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: char * pst
* Parameter: int n
************************************ /
void SaveName(char* pst, int n);
/ ************************************
* Method:    SaveName
* FullName:  SaveName
* Access:    public 
* Returns:   void
* Qualifier:
************************************ /
void SaveName();
/ ************************************
* Method:    ReadName
* FullName:  ReadName
* Access:    public 
* Returns:   void
* Qualifier:
************************************ /
void ReadName();
/ ************************************
* Method:    ClearFile
* FullName:  ClearFile
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: char * name
* Parameter: int mark
************************************ /
void ClearFile(char* name, int mark);
/ ************************************
* Method:    DeleteName
* FullName:  DeleteName
* Access:    public 
* Returns:   void
* Qualifier:
* Parameter: int mark
* Parameter: int index
************************************ /
void DeleteName(int mark, int index);
*/
