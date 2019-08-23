// TankGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Game.h"
int main()
{
	system("mode con cols=140 lines=50");
	g_ReadMap.InitMap();
	g_EditMap.InitMap();
	gPMapName = (char(*)[20])calloc(gMaxNum, 20);
	gPRecordName = (char(*)[20])calloc(gMaxNum, 20);
	Game GameMain;
	GameMain.WelcomeUI();
	
	free(gPMapName);
	gPMapName = nullptr;
	free(gPRecordName);
	gPRecordName = nullptr;
}

