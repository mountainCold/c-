#include "Data.h"
HANDLE g_hout = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE g_hint = GetStdHandle(STD_INPUT_HANDLE);

bool g_Game = true;
int gContinue = 0;
extern int gLevel = 1;//当前关卡数
int gMode = 1;
int gMaxNum = 10;
int gMCount = 0;
int gRCount = 0;
char(*gPMapName)[20] ;
char(*gPRecordName)[20] ;
COORD MousePos = { 0,0 };






