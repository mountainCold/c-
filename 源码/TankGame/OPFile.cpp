#include "OPFile.h"
#include "Data.h"
#include "MapTank.h"
#include "Tank.h"
#include "Bullet.h"
OPFile::OPFile()
{
}

OPFile::~OPFile()
{
}
void OPFile::ReadRecord(char* mName)
{
	char str[30];
	strcpy_s(str, 30, "data//");
	strcat_s(str, 30, mName);
	strcat_s(str, 30, ".rec");


	FILE* pfile;
	errno_t err = fopen_s(&pfile, str, "rb");

	if (err != 0)
	{
		return;
	}
	//先读初始地图
	fread(&Map, sizeof(Map), 1, pfile);
	//再读坦克	//然后读子弹
	for (int i = 0; i < 5; ++i)
	{
		fread(&(Ptank[i]->bulletStat), 4, 1, pfile);
		fread(&(Ptank[i]->x), 4, 1, pfile);
		fread(&(Ptank[i]->y), 4, 1, pfile);
		fread(&(Ptank[i]->dir), 4, 1, pfile);
		fread(&(Ptank[i]->sign), 4, 1, pfile);
		fread(&(Ptank[i]->heart), 4, 1, pfile);
		fread(&(Pbullet[i]->dir), 4, 1, pfile);
		fread(&(Pbullet[i]->sign), 4, 1, pfile);
		fread(&(Pbullet[i]->x), 4, 1, pfile);
		fread(&(Pbullet[i]->y), 4, 1, pfile);
		fread(&(Pbullet[i]->Grade), 4, 1, pfile);
		Pbullet[i]->v = "○";

	}

	//读游戏模式 单人or双人
	fread(&gMode, 4, 1, pfile);
	fclose(pfile);
}
void OPFile::SaveRecord()
{
	char mName[20];
	system("cls");
	DwFrame(18, 38, 16, 24, 5);
	WriteChar(22, 20, "请输入存档名称:", 7);
	COORD cor = { 48,22 };
	SetConsoleCursorPosition(g_hout, cor);
	scanf_s("%s", mName, 20);

	system("cls");
	char str[30];
	strcpy_s(str, 30, "data//");
	strcat_s(str, 30, mName);
	strcat_s(str, 30, ".rec");
	SaveName(mName, 1);
	FILE* pfile;
	errno_t err = fopen_s(&pfile, str, "wb");

	if (err != 0)
	{
		return;
	}
	//先存初始地图
	fwrite(&Map, sizeof(MapTank), 1, pfile);
	//再存坦克然后存子弹
	for (int i = 0; i < 5; ++i)
	{
		fwrite(&(Ptank[i]->bulletStat), 4, 1, pfile);
		fwrite(&(Ptank[i]->x), 4, 1, pfile);
		fwrite(&(Ptank[i]->y), 4, 1, pfile);
		fwrite(&(Ptank[i]->dir), 4, 1, pfile);
		fwrite(&(Ptank[i]->sign), 4, 1, pfile);
		fwrite(&(Ptank[i]->heart), 4, 1, pfile);
		fwrite(&(Pbullet[i]->dir), 4, 1, pfile);
		fwrite(&(Pbullet[i]->sign), 4, 1, pfile);
		fwrite(&(Pbullet[i]->x), 4, 1, pfile);
		fwrite(&(Pbullet[i]->y), 4, 1, pfile);
		fwrite(&(Pbullet[i]->Grade), 4, 1, pfile);
	}
	//存游戏模式 单人or双人
	fwrite(&gMode, 4, 1, pfile);
	fclose(pfile);
	//SaveName(mName, 1);
}

void OPFile::ReadMap(char* mName)
{
	char str[30];
	strcpy_s(str, 30, "data//");
	strcat_s(str, 30, mName);
	strcat_s(str, 30, ".map");

	FILE* pfile;
	errno_t err = fopen_s(&pfile, str, "rb");;
	if (err != 0)
	{

		return;
	}
	fread(&g_InitMap, sizeof(MapTank), 1, pfile);

	fclose(pfile);
}
void OPFile::SaveMap()
{
	char mName[20];
	system("cls");
	DwFrame(18, 38, 16, 24, 5);
	WriteChar(22, 20, "请输入地图名称:", 7);
	COORD cor = { 48,22 };
	SetConsoleCursorPosition(g_hout, cor);
	scanf_s("%s", mName, 20);
	system("cls");
	char str[30];
	strcpy_s(str, 30, "data//");
	strcat_s(str, 30, mName);
	strcat_s(str, 30, ".map");
	SaveName(mName, 0);
	FILE* pfile;
	errno_t err = fopen_s(&pfile, str, "wb");

	if (err != 0)
	{
		return;
	}
	fwrite(&g_EditMap, sizeof(MapTank), 1, pfile);

	fclose(pfile);
	//SaveName(mName, 0);
}
void OPFile::SaveName(char* pst, int n)
{
	FILE* pfile;
	errno_t err = fopen_s(&pfile, "data\\Name.tank", "wb");
	if (err != 0)
	{
		return;
	}
	fwrite(&gMaxNum, 4, 1, pfile);
	if (n == 0)
	{
		for (int i = 0; i < gMCount; i++)
		{
			if (strcmp(pst, gPMapName[i]) == 0)
			{
				return;
			}
		}
		gMCount++;
		fwrite(&gMCount, 4, 1, pfile);
		fwrite(&gRCount, 4, 1, pfile);
		if (gMCount >= gMaxNum)
		{
			gMaxNum += 10;
			gPMapName = (char(*)[20])realloc(gPMapName, 20 * gMaxNum);
		}


		strcpy_s(*(gPMapName + gMCount - 1), 20, pst);
		fwrite(gPMapName, 20 * gMCount, 1, pfile);
		if (gRCount != 0)
		{
			fwrite(gPRecordName, 20 * gRCount, 1, pfile);
		}
	}
	else if (n == 1)
	{

		if (gRCount >= gMaxNum)
		{
			gMaxNum += 10;
			gPRecordName = (char(*)[20])realloc(gPRecordName, 20 * gMaxNum);
		}

		gRCount++;
		fwrite(&gMCount, 4, 1, pfile);
		fwrite(&gRCount, 4, 1, pfile);
		if (gMCount != 0)
		{
			fwrite(gPMapName, 20 * gMCount, 1, pfile);
		}
		strcpy_s(*(gPRecordName + gRCount - 1), 20, pst);
		fwrite(gPRecordName, 20 * gRCount, 1, pfile);
	}

	fclose(pfile);
}
void OPFile::SaveName()
{
	FILE* pfile;
	errno_t err = fopen_s(&pfile, "data\\Name.tank", "wb");
	if (err != 0)
	{
		return;
	}

	if (gMCount < gMaxNum - 10)
	{
		gMaxNum -= 10;
		gPMapName = (char(*)[20])realloc(gPMapName, 20 * gMaxNum);
	}
	if (gRCount < gMaxNum - 10)
	{
		gMaxNum -= 10;
		gPRecordName = (char(*)[20])realloc(gPRecordName, 20 * gMaxNum);
	}
	fwrite(&gMaxNum, 4, 1, pfile);
	fwrite(&gMCount, 4, 1, pfile);
	fwrite(&gRCount, 4, 1, pfile);
	if (gMCount != 0)
	{
		fwrite(gPMapName, 20 * gMCount, 1, pfile);
	}
	if (gRCount != 0)
	{
		fwrite(gPRecordName, 20 * gRCount, 1, pfile);
	}
	fclose(pfile);
}
void OPFile::ReadName()
{
	FILE* pfile;
	errno_t err = fopen_s(&pfile, "data\\Name.tank", "rb");
	if (err != 0)
	{
		return;
	}
	fread(&gMaxNum, 4, 1, pfile);
	fread(&gMCount, 4, 1, pfile);
	fread(&gRCount, 4, 1, pfile);
	if (gMCount != 0)
	{
		fread(gPMapName, 20 * gMCount, 1, pfile);
	}
	if (gRCount != 0)
	{
		fread(gPRecordName, 20 * gRCount, 1, pfile);
	}
	fclose(pfile);
}
void OPFile::ClearFile(char* name, int mark)
{
	system("cls");
	char str[30];
	if (mark == 0)
	{
		strcpy_s(str, 30, "data//");
		strcat_s(str, 30, name);
		strcat_s(str, 30, ".map");
	}
	else if (mark == 1)
	{
		strcpy_s(str, 30, "data//");
		strcat_s(str, 30, name);
		strcat_s(str, 30, ".rec");
	}
	else
	{
		return;
	}
	if (remove(str) == 0)
	{
		printf("删除 成功");

	}
	else
	{
		perror("remove");
	}
	system("cls");

}
void OPFile::DeleteName(int mark, int index)
{
	if (mark == 0)
	{
		for (int i = 0; i < gMCount - 1; i++)
		{
			if (i >= index)
			{
				strcpy_s(*(gPMapName + i), 20, *(gPMapName + i + 1));
			}
		}
		gMCount--;
		gPMapName = (char(*)[20])realloc(gPMapName, gMCount * 20);
		char* p = *(gPMapName + 0);
		char* p1 = *(gPMapName + 1);
		char* p2 = *(gPMapName + 2);
	}
	else if (mark == 1)
	{
		for (int i = 0; i < gRCount - 1; i++)
		{
			if (i >= index)
			{
				strcpy_s(*(gPRecordName + i), 20, *(gPRecordName + i + 1));
			}
		}
		gRCount--;
		gPRecordName = (char(*)[20])realloc(gPRecordName, gRCount * 20);
	}

}