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
	//���߽�
	for (int i = 59; i < 70; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 59 || i == 69 || j == 0 || j == 49)
			{
				WriteChar(i, j, "��");
			}
		}
	}
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (nMap[j][i] == ��ǽ)
			{
				WriteChar(i, j, "��", 7);
			}
			if (nMap[j][i] == ��ǽ)
			{
				WriteChar(i, j, "��", 6);
			}
			if (nMap[j][i] >= �ݴ�)
			{
				WriteChar(i, j, "��", 5);
			}
			if (nMap[j][i] == ����)
			{
				WriteChar(i, j, "��", 5);
			}
			if (nMap[j][i] == ����)
			{
				WriteChar(i, j, "��", 9);
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
				nMap[j][i] = ��ǽ;
			}
		}
	}
	for (int j = 46; j < 49; j++)
	{
		for (int i = 28; i < 32; i++)
		{
			if (i > 28 && i < 31 && j>46 && j <= 48)
			{
				nMap[j][i] = ����;
			}
			else
			{
				//nMap[j][i] = ��ǽ;
				nMap[j][i] = ��ǽ;
			}
		}
	}
}
void MapTank::WriteEditMap()
{
	//���߽�
	for (int i = 59; i < 70; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == 59 || i == 69 || j == 0 || j == 49)
			{
				WriteChar(i, j, "��");
			}
		}
	}
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (nMap[j][i] == ��ǽ)
			{
				WriteChar(i, j, "��", 7);
			}
			if (nMap[j][i] == ��ǽ)
			{
				WriteChar(i, j, "��", 6);
			}
			if (nMap[j][i] >= �ݴ�)
			{
				WriteChar(i, j, "��", 5);
			}
			if (nMap[j][i] == ����)
			{
				WriteChar(i, j, "��", 5);
			}
			if (nMap[j][i] == ����)
			{
				WriteChar(i, j, "��", 9);
			}
		}
	}
}
void MapTank::EditMap()
{
	system("cls");

	g_EditMap.WriteMap();
	WriteChar(63, 3, "̹�˴�ս", 7);
	WriteChar(61, 5, "�༭˵��:", 7);
	WriteChar(61, 7, "���������ͼ��:", 7);
	WriteChar(62, 8, "ѡ������:", 7);
	WriteChar(61, 10, "�������:", 7);
	WriteChar(61, 12, "������:", 4);
	const char* str = "��";
	int num = ��ǽ;
	WriteChar(61, 15, "����   ��ǽ", 6);
	WriteChar(61, 17, "����   ��ǽ", 7);
	WriteChar(61, 19, "����   �ݴ�", 3);
	WriteChar(61, 21, "�ˡ�   ����", 4);
	WriteChar(61, 23, "XXXX   �յ�");
	WriteChar(61, 26, "���");
	WriteChar(63, 26, "�˳�", 4);
	WriteChar(61, 28, "���");
	WriteChar(63, 28, "���汾��", 4);
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
			str = "��";
			num = ��ǽ;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 17)
		{
			str = "��";
			num = ��ǽ;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 19)
		{
			str = "��";
			num = �ݴ�;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 21)
		{
			str = "��";
			num = ����;
		}
		else if (MousePos.X >= 122 && MousePos.X <= 134 && MousePos.Y == 23)
		{
			str = "  ";
			num = �յ�;
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
			if (nMap[j][i]!=����)
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


