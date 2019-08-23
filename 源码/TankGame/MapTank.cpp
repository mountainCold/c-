#include "MapTank.h"
MapTank Map;
MapTank g_InitMap;
MapTank g_EditMap;
MapTank g_ReadMap;
void MapTank::SetMap(int x, int y, int val)
{
	nMap[y][x] = val;
}
int  MapTank::GetMapVal(int x, int y)
{
	if (x < 0 || y < 0 || x>59 || y>49)
	{
		return -1;
	}
	return nMap[y][x];
}
void MapTank::WriteMap()
{
	//画边界
	for (int i = 59; i < 70; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 59 || i == 69 || j == 0 || j == 49)
			{
				WriteChar(i, j, "■");
			}
		}
	}
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (nMap[j][i] == 铁墙)
			{
				WriteChar(i, j, "■", 7);
			}
			if (nMap[j][i] == 土墙)
			{
				WriteChar(i, j, "▓", 6);
			}
			if (nMap[j][i] >= 草丛)
			{
				WriteChar(i, j, "※", 5);
			}
			if (nMap[j][i] == 河流)
			{
				WriteChar(i, j, "∷", 5);
			}
			if (nMap[j][i] == 基地)
			{
				WriteChar(i, j, "⊙", 9);
			}
		}
	}
}
void MapTank::InitMap()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 0 || i == 59 || j == 0 || j == 49)
			{
				nMap[j][i] = 铁墙;
			}
		}
	}
	for (int j = 46; j < 49; j++)
	{
		for (int i = 28; i < 32; i++)
		{
			if (i > 28 && i < 31 && j>46 && j <= 48)
			{
				nMap[j][i] = 基地;
			}
			else
			{
				//nMap[j][i] = 铁墙;
				nMap[j][i] = 土墙;
			}
		}
	}
}
void MapTank::WriteEditMap()
{
	//画边界
	for (int i = 59; i < 70; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 59 || i == 69 || j == 0 || j == 49)
			{
				WriteChar(i, j, "■");
			}
		}
	}
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (nMap[j][i] == 铁墙)
			{
				WriteChar(i, j, "■", 7);
			}
			if (nMap[j][i] == 土墙)
			{
				WriteChar(i, j, "▓", 6);
			}
			if (nMap[j][i] >= 草丛)
			{
				WriteChar(i, j, "※", 5);
			}
			if (nMap[j][i] == 河流)
			{
				WriteChar(i, j, "∷", 5);
			}
			if (nMap[j][i] == 基地)
			{
				WriteChar(i, j, "⊙", 9);
			}
		}
	}
}
void MapTank::EditMap()
{
	system("cls");

	g_EditMap.WriteMap();
	WriteChar(63, 3, "坦克大战", 7);
	WriteChar(61, 5, "编辑说明:", 7);
	WriteChar(61, 7, "点击击以下图标:", 7);
	WriteChar(62, 8, "选择物体:", 7);
	WriteChar(61, 10, "左键绘制:", 7);
	WriteChar(61, 12, "点击清空:", 4);
	const char* str = "▓";
	int num = 土墙;
	WriteChar(61, 15, "▓▓   土墙", 6);
	WriteChar(61, 17, "■■   铁墙", 7);
	WriteChar(61, 19, "※※   草丛", 3);
	WriteChar(61, 21, "∷∷   河流", 4);
	WriteChar(61, 23, "XXXX   空地");
	WriteChar(61, 26, "点击");
	WriteChar(63, 26, "退出", 4);
	WriteChar(61, 28, "点击");
	WriteChar(63, 28, "保存本地", 4);
	bool bedit = true;
	int nMessage = 0;
	while (bedit)
	{
		ShowCuror();
		nMessage = MessageListener(1);
		if (nMessage == 27)
		{
			bedit = false;
			system("cls");
		}
		else if (nMessage == 13)
		{
			SaveMap();
			ReadName();
		}
		if (MousePos.X >= 2 && MousePos.X < 118 && MousePos.Y>0 && MousePos.Y < 49)
		{
			if (MousePos.X > 56 && MousePos.X < 62 && MousePos.Y>46 && MousePos.Y <= 48)
			{
			}
			else
			{
				if (num == 10)
				{
					WriteChar(MousePos.X / 2, MousePos.Y, str, 9);
				}
				else if (num == 30)
				{
					WriteChar(MousePos.X / 2, MousePos.Y, str, 5);
				}
				else
				{
					WriteChar(MousePos.X / 2, MousePos.Y, str, 8 - num);
				}
				g_EditMap.SetMap(MousePos.X / 2, MousePos.Y, num);
			}
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 15)
		{
			str = "▓";
			num = 土墙;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 17)
		{
			str = "■";
			num = 铁墙;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 19)
		{
			str = "※";
			num = 草丛;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 21)
		{
			str = "∷";
			num = 河流;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 23)
		{
			str = "  ";
			num = 空地;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 26)
		{
			bedit = false;
			system("cls");
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 12)
		{
			g_EditMap.Clear();
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 28)
		{
			SaveMap();
			ReadName();

			bedit = false;
		}
		MousePos = { 0,0 };	
	}
	system("cls");
}
void MapTank::Clear()
{
	for (int i=1;i<59;++i)
	{
		for (int j=1;j<49;++j)
		{
			if (nMap[j][i]!=基地)
			{
				WriteChar(i, j, "  ");
				nMap[j][i] = 0;
			}
		}
	}
}
bool MapTank::operator=( MapTank map)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			nMap[i][j] =map.GetMapVal(j,i);
		}
	}
	return true;
}


