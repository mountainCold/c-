#pragma once
#include "Data.h"
#include "Logic.h"
#include <fstream>
#include "OPFile.h"

class MapTank:virtual public OPFile
{
public:

	void SetMap(int x, int y, int val);
	int GetMapVal(int x, int y);
	void WriteMap();
	void InitMap();
	void WriteEditMap();
	void EditMap();
	void Clear();
	bool operator=(MapTank map);

private:
	int nMap[50][60] = { 0 };
};
extern MapTank Map; //地图信息
extern MapTank g_InitMap; //被读取地图
extern MapTank g_EditMap; //待编辑地图
extern MapTank g_ReadMap; //游戏载入地图