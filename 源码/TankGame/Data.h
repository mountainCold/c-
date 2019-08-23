#pragma once
#include<Windows.h>
#include <stdio.h>
#define  空地 0
#define  铁墙 1  //不可摧毁障碍物
#define  土墙 2 //可摧毁障碍物
#define  河流 3 //子弹可以穿过 坦克不能通过
#define  草丛 30 //具有遮挡功能
#define  基地 10
#define  食物 9
#define  我方坦克1 4
#define  我方坦克2 5
#define  敌方坦克1 6
#define  敌方坦克2 7
#define  敌方坦克3 8
#define  我方子弹1 14
#define  我方子弹2 15
#define  敌方子弹1 16
#define  敌方子弹2 17
#define  敌方子弹3 18
#define KEYDOWN(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?1:0)
extern HANDLE g_hout; //输出句柄
extern HANDLE g_hint;  //输入句柄
extern bool g_Game; //游戏逻辑循环判断
extern COORD MousePos; //鼠标点击位置
extern int gLevel;//当前关卡数
extern int gMaxNum;//最大容量
extern int gContinue;//继续游戏
extern int gMode;//游戏模式单人or双人
extern int gMCount;//Map 索引文件个数
extern int gRCount;//Record 索引文件个数
extern char(*gPMapName)[20];//地图索引名称数组
extern char(*gPRecordName)[20];//存档索引名称数组










