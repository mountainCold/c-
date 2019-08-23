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
extern MapTank Map; //��ͼ��Ϣ
extern MapTank g_InitMap; //����ȡ��ͼ
extern MapTank g_EditMap; //���༭��ͼ
extern MapTank g_ReadMap; //��Ϸ�����ͼ