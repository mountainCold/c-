#include "Game.h"
#include "Tank.h"
#include "MapTank.h"
#include <conio.h>
#include <time.h>
bool Game::WelcomeUI()
{
	HomePage();
	ReadName();
	bool bhome = true;
	ReadMap(*gPMapName);
	g_ReadMap = g_InitMap;
	while (bhome)
	{
		WriteChar(30, 18, "̹�˴�ս");
		HomePage();
		ShowCuror();
		if (gContinue == 1)
		{
			WriteChar(26, 20, "7  ������Ϸ");
		}
		int hmess = -1;
		WriteChar(26, 22, "1  ������Ϸ");
		WriteChar(26, 24, "2  ˫����Ϸ");
		WriteChar(26, 26, "3  ��ͼ�༭");
		WriteChar(26, 28, "4  ѡ���ͼ");
		WriteChar(26, 30, "5  ��ȡ�浵");
		WriteChar(26, 32, "6  �˳���Ϸ");
		while (_kbhit() == 1)
		{			
			_getch();			
		}
		hmess = MessageListener();

		if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 22)
		{
			hmess = 1;
		}
		else if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 24)
		{
			hmess = 2;
		}
		else if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 20)
		{
			hmess = 7;
		}
		else if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 26)
		{
			hmess = 3;
		}
		else if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 28)
		{
			hmess = 4;
		}
		else if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 30)
		{
			hmess = 5;
		}
		else if (MousePos.X >= 48 && MousePos.X <= 76 && MousePos.Y == 32)
		{
			hmess = 6;
		}
		MousePos = { 0,0 };
		if (hmess == 1)
		{
			Map = g_ReadMap;
			if (gLevel == 1)
			{
				InitTankAndBulletInfo();
			}
			gMode = 1;
			StartGame(gMode);
		}
		else if (hmess == 2)
		{
			Map = g_ReadMap;
			if (gLevel == 1)
			{
				InitTankAndBulletInfo();
			}
			gMode = 2;
			StartGame(gMode);
		}
		else if (hmess == 7)
		{
			if (gContinue == 1)
			{
				StartGame(gMode);
			}

		}
		else if (hmess == 3)
		{
			/*InitMap();*/
			g_EditMap.EditMap();
		}
		else if (hmess == 4)
		{
			MapManage();
		}
		else if (hmess == 5)
		{
			if (RecordManage())
			{
				StartGame(gMode);
			}
			
		}
		else if (hmess == 6)
		{
			bhome = false;
		}
		if (gLevel > 1)
		{
			Map = g_ReadMap;
			StartGame(gMode);
		}

	}
	return true;
}
void Game::HomePage()
{
	SetConsoleTitle(L"̹�˴�ս");
	for (int i = 0; i < 70; i += 4)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i > 23 && i < 43 && j>15 && j < 35)
			{
			}
			else
			{
				if (j % 4 == 0)
				{
					WriteChar(i, j, "̹", 70);
				}if (j % 4 == 1)
				{
					WriteChar(i, j, "��", 61);
				}if (j % 4 == 2)
				{
					WriteChar(i, j, "��", 82);
				}if (j % 4 == 3)
				{
					WriteChar(i, j, "ս", 53);
				}
			}
		}
	}

}
bool Game::InitTankAndBulletInfo()
{
  for (int i=0;i<5;++i)
  {
	  (*Ptank[i]).SetTank(i + 4);
	  *Pbullet[i] = (*Ptank[i]).bull;
  }
  return true;
}
void Game::GameShows()
{
	SetConsoleTitle(L"������Ϸ");
	WriteChar(62, 2, "̹�˴�ս", 7);
	WriteChar(61, 4, "��Ϸ˵��:", 7);
	WriteChar(61, 6, "Space :", 7);
	WriteChar(64, 6, "����ͣ:", 7);
	WriteChar(61, 8, "ESC", 7);
	WriteChar(63, 8, "��ǿ���˳�", 7);
	WriteChar(61, 10, "1|2�����:", 7);
	WriteChar(61, 12, "w|5   ��", 7);
	WriteChar(61, 14, "s|2   ��", 7);
	WriteChar(61, 16, "a|1   ��", 7);
	WriteChar(61, 18, "d|3   ��", 7);
	WriteChar(61, 20, "j|4    ����", 7);
	WriteChar(60, 21, "==================", 7);
	WriteChar(61, 22, "�о�������", 7);
	WriteTank(62, 24, 6);
	WriteChar(65, 24, "X", 7);
	WriteTank(62, 28, 7);
	WriteChar(65, 28, "X", 7);
	WriteTank(62, 32, 8);
	WriteChar(65, 32, "X", 7);
	WriteChar(61, 35, "�ҷ�������", 7);
	WriteTank(62, 37, 4);
	WriteChar(65, 37, "X", 7);
	WriteChar(61, 46, "��ǰ�ؿ���", 7);
	WriteChar(67, 46, gLevel, 7);
	if (gMode > 1)
	{
		WriteTank(62, 41, 5);
		WriteChar(65, 41, "X", 7);
	}
}
bool Game::StartGame(int x)
{
	system("cls");
	PlaySound(L"sound\\��ʼ����.wav", NULL, SND_FILENAME | SND_ASYNC);
	
	int Tnum = 0, Anum = 0, Fnum = 0, Bnum = 0;//��ʱ����̹�˺��ӵ�,��ʳ��
	int Bfood = 0; //ʳ���Ƿ���� 0������ 1����
	int fonums = 0; //ˢ�´���
	int Foodx = 0; //ʳ������
	int Foody = 0;
	gContinue = 0;
	char ch = 0;
	char ch1 = 0;
	char ch2 = 0;
	char bch1 = 0;
	char bch2 = 0;
	g_Game = true;
	Map.WriteMap();
	//��������
	GameShows();
	for (int i = 0; i < 5; i++)
	{
		if ((*Ptank[i]).bulletStat == 0)
		{
			if ((*Pbullet[i]).DrawObj())
			{
				(*Ptank[i]).bulletStat = 1;
			}
		}
	}	
	t4.DrawObj();
	t6.DrawObj();
	t7.DrawObj();
	t8.DrawObj();
	if (x > 1)
	{
		t5.DrawObj();
	}
	while (g_Game)
	{
		int kills = 0;//����3ʱ��Ϸ������
		ShowCuror();
		if (Tnum >= 6)
		{
			Tnum = 0;
			KeyListener(ch1, ch2, bch1, bch2);
			if (g_Game==false)
			{
				system("cls");
				return false;
			}
			if (ch1 == 32)
			{
				system("cls");
				ch = 0;
				DwFrame(22, 42, 16, 28, 5);
				SetConsoleTitle(L"��Ϸ��ͣ");
				while (ch != 32)
				{
					WriteChar(30, 19, "��Ϸ��ͣ��", 7);
					WriteChar(25, 21, "�밴Escape������������", 7);
					WriteChar(25, 23, "�밴�ո��������Ϸ", 7);
					WriteChar(25, 25, "���س������汾�ز��˳�", 7);
					ch = KeyListener();
					if (ch == 27)
					{
						gContinue = 1;
						system("cls");
						return true;
					}
					if (ch == 13)
					{
						SaveRecord();
						ch = 27;
						break;
					}

				}
				system("cls");
				Map.WriteMap();
				GameShows();
			}
			if (ch1 == 'w' || ch1 == 's' || ch1 == 'a' || ch1 == 'd')
			{
				t4.dir = ch1;
			}
			if (ch2 == 'w' || ch2 == 's' || ch2 == 'a' || ch2 == 'd')
			{
				t5.dir = ch2;
			}
			t4.OpCodeDetection(ch1);
			if (bch1 =='j')
			{
				t4.OpenFire();
			}
			if (x > 1)
			{
				if (t4.heart == 0 && t5.heart == 0)
				{
					g_Game = false;
				}
				t5.OpCodeDetection( ch2);
				if (bch2=='j')
				{
					t5.OpenFire();
				}
				
			}
			else
			{
				if (t4.heart == 0)
				{
					g_Game = false;
				}
			}

		}
		for (int i = 2; i < 5; i++)
		{
			if (Ptank[i]->heart > 0)
			{

				int nsign = (*Ptank[i]).RangeSensing();
				if ((*Ptank[i]).DodgeBullet()==1)
				{
					continue;
				}
				if (nsign==4)
				{
					(*Ptank[i]).GetPath(t4.x, t4.y);	
				}
				else if (nsign ==5)
				{
					(*Ptank[i]).GetPath(t5.x, t5.y);
				}
				else
				{
					(*Ptank[i]).n_path.clear();
				}
				(*Ptank[i]).AutoMoveForOPPTank(Anum + gLevel/3);
			}
			else
			{
				kills++;
			}
		}
		//����ʳ��
		if (Bfood == 0)
		{
			srand((int)time(NULL));
			if (rand() % 3 == 1)
			{
				if (kills == fonums)
				{
					srand((int)time(NULL));
					Foodx = rand() % 56 + 1;
					Foody = rand() % 46 + 1;
					if (WriteFood(Foodx, Foody) == 1)
					{
						fonums++;
						Bfood = 1;
					}
				}
			}
		}
		else
		{
			Fnum++;
		}
		if (kills == 3)
		{
			PlaySound(L"sound\\ʤ��.wav", NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			DwFrame(22, 42, 16, 37, 5);
			SetConsoleTitle(L"��Ϸʤ��");
			WriteTank(29, 19, 6);
			WriteTank(29, 23, 7);
			WriteTank(29, 27, 8);
			WriteChar(33, 19, "X", 7);
			WriteChar(33, 23, "X", 7);
			WriteChar(33, 27, "X", 7);
			WriteChar(35, 19, 3 + gLevel / 3 , 7);
			WriteChar(35, 23, 3 + gLevel / 3 , 7);
			WriteChar(35, 27, 3 + gLevel / 3, 7);
			WriteChar(26, 31, "�ɵ�Ư����ָ�ӹٸ��£�", 7);
			WriteChar(26, 33, "���س���������һ��", 7);
			WriteChar(26, 35, "��ESc������������", 7);
			ch = 0;
			while (true)
			{
				ch = KeyListener();
				if (ch == 13)
				{
					t4.DelObj();
					t5.DelObj();
					t4.x = 26; t4.y = 47;
					t5.x = 33; t5.y = 47;
					t6.heart = 3 + gLevel /3;
					t7.heart = 3 + gLevel /3;
					t8.heart = 3 + gLevel /3;
					ReadMap(*(gPMapName + gLevel%3));
					g_ReadMap = g_InitMap;
					gLevel++;
					system("cls");
					g_Game = false;
					return true;

				}
				else if (ch == 27)
				{
					gLevel = 1;
					system("cls");
					g_Game = false;
					return false;
				}

			}


		}
		if (Bnum >= 2)
		{
			Bnum = 0;
			for (int i = 0; i < 5; i++)
			{
				if ((*Ptank[i]).bulletStat == 0)
				{
					if ((*Pbullet[i]).DrawObj())
					{
						(*Ptank[i]).bulletStat = 1;
					}
				}
			}
		}

		WriteChar(67, 24, t6.heart, 7);
		WriteChar(67, 28, t7.heart, 7);
		WriteChar(67, 32, t8.heart, 7);
		WriteChar(67, 37, t4.heart, 7);

		if (x > 1)
		{
			WriteChar(67, 41, t5.heart, 7);
		}
		Sleep(5);
		Tnum++;
		Bnum++;
		if (Anum >= 7)
		{
			Anum = 0;
		}
		Anum++;
		if (Fnum >= 1000)
		{
			WriteChar(Foodx, Foody, "  ");
			Map.SetMap(Foodx, Foody,0);
			Bfood = 0;
			Fnum = 0;
		}
		if (g_Game==false)
		{
			PlaySound(L"sound\\ʧ��.wav", NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			DwFrame(22, 42, 16, 35, 5);
			SetConsoleTitle(L"��Ϸʧ��");
			gLevel = 1;
			WriteTank(29, 19, 6);
			WriteTank(29, 23, 7);
			WriteTank(29, 27, 8);
			WriteChar(33, 19, "X", 7);
			WriteChar(33, 23, "X", 7);
			WriteChar(33, 27, "X", 7);
			WriteChar(35, 19, 3 + gLevel / 3 - t6.heart, 7);
			WriteChar(35, 23, 3 + gLevel / 3 - t7.heart, 7);
			WriteChar(35, 27, 3 + gLevel / 3 - t8.heart, 7);
			WriteChar(27, 31, "���٣����ٽ�������", 7);
			WriteChar(27, 33, "���س�������������", 7);
			ch = 0;
			while (ch != 13)
			{
				if (_kbhit() == 1)
				{
					ch = _getch();
				}
			}
			system("cls");
		}
	
	}
	system("cls");
	return true;

}
void Game::MapManage()

{
	SetConsoleTitle(L"��ͼ����");

	int page = 1;
	system("cls");

	bool stat = true;
	int code = 0;
	int  sub = -1;
	int del = -1;
	int tem = 0;
	while (stat)
	{
		int n = gMCount / 7 + 1;
		ShowCuror();
		DwFrame(17, 43, 10, 31, 6);
		WriteChar(22, 12, "��ͼ�б�", 7);
		WriteChar(29, 12, page, 7);
		WriteChar(30, 12, "/", 7);
		WriteChar(31, 12, n, 7);
		WriteChar(19, 13, "���", 7);
		WriteChar(23, 13, "��ͼ����", 7);
		WriteChar(19, 30, "��", 7);
		WriteChar(20, 30, "ESC", 5);
		WriteChar(22, 30, "������", 7);
		WriteChar(27, 30, "�س���", 5);
		WriteChar(30, 30, "ȷ��", 7);
		WriteChar(34, 30, "��ѡ�����:", 7);
		WriteChar(19, 15, "1", 7);
		WriteChar(19, 17, "2", 7);
		WriteChar(19, 19, "3", 7);
		WriteChar(19, 21, "4", 7);
		WriteChar(19, 23, "5", 7);
		WriteChar(19, 25, "6", 7);
		WriteChar(19, 27, "7", 7);
		for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
		{

			if (i < gMCount)
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
				if (i == sub)
				{
					WriteChar(23, 15 + tem, *(gPMapName + i), 9);
				}
				else {
					WriteChar(23, 15 + tem, *(gPMapName + i), 7);
				}
				if (del == i)
				{
					WriteChar(34, 15 + tem, "ɾ��", 9);
				}
				else
				{
					WriteChar(34, 15 + tem, "ɾ��", 7);
				}
				
			}
			else
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
			}
			tem += 2;
		}
		tem = 0;
		bool sure = false;
		if (page == 1)
		{
			WriteChar(28, 12, "��", 4);

		}
		else
		{
			WriteChar(28, 12, "<<", 4);
		}
		if (page == n)
		{
			WriteChar(32, 12, "��", 4);
		}
		else
		{
			WriteChar(32, 12, ">>", 4);
		}
		int code = MessageListener();
		if (page == 1)
		{
			WriteChar(28, 12, "��", 4);

		}
		else
		{
			WriteChar(28, 12, "<<", 4);
			if (MousePos.X >= 56 && MousePos.X <= 58 && MousePos.Y == 12)
			{
				for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
				{
					WriteChar(23, 15 + tem, "                                 ", 7);
					tem += 2;
				}
				page--;
				tem = 0;
			}
		}
		if (page == n)
		{
			WriteChar(32, 12, "��", 4);
		}
		else
		{
			WriteChar(32, 12, ">>", 4);
			if (MousePos.X >= 64 && MousePos.X <= 66 && MousePos.Y == 12)
			{
				for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
				{
					WriteChar(23, 15 + tem, "                                 ", 7);
					tem += 2;
				}
				page++;
				tem = 0;
			}
		}

		if (code >= 1 && code <= 7)
		{
			sub = (page - 1) * 7 + code - 1;
			sure = true;
		}
		else if (code == 27)
		{
			stat = false;
		}
		else if (code == 13)
		{
			sure = true;
			stat = false;
		}
		code = 0;

		if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 15)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 0;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 0;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 17)
		{


			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 1;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 1;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 19)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 2;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 2;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 21)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 3;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 3;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 23)
		{
			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 4;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 4;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 25)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 5;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 5;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 27)
		{
			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 6;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 6;
				del = -1;
			}
		}
		else if (MousePos.X >= 40 && MousePos.X <= 50 && MousePos.Y == 30)
		{
			stat = false;
			MousePos = { 0,0 };
		}
		else if (MousePos.X >= 52 && MousePos.X <= 60 && MousePos.Y == 30)
		{
			sure = true;
			stat = false;
			MousePos = { 0,0 };
		}
		else
		{
			sub = -1;
			del = -1;
		}
		if (sure)
		{
			if (del >= 0)
			{

				ClearFile(*(gPMapName + del), 0);
				DeleteName(0, del);
				SaveName();
				ReadName();

			}
			else if (sub >= 0)
			{
				if (sub < gMCount)
				{
					ReadMap(*(gPMapName + sub));
					g_ReadMap = g_InitMap;
					g_EditMap = g_InitMap;
				}

			}
		}
		for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
		{

			if (i < gMCount)
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
				if (i == sub)
				{
					WriteChar(23, 15 + tem, *(gPMapName + i), 9);
				}
				else {
					WriteChar(23, 15 + tem, *(gPMapName + i), 7);
				}
				if (del == i)
				{
					WriteChar(34, 15 + tem, "ɾ��", 9);
				}
				else
				{
					WriteChar(34, 15 + tem, "ɾ��", 7);
				}
			}
			else
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
			}
			tem += 2;
		}
		tem = 0;
	}
	system("cls");
}
bool Game::RecordManage()
{
	SetConsoleTitle(L"��������");
	int page = 1;
	system("cls");
	bool stat = true;
	int code = 0;
	int sub = -1;
	int del = -1;
	while (stat)
	{
		DwFrame(17, 43, 10, 31, 6);
		ShowCuror();
		int n = gRCount / 7 + 1;
		WriteChar(22, 12, "�����б�", 7);
		WriteChar(29, 12, page, 7);
		WriteChar(30, 12, "/", 7);
		WriteChar(31, 12, n, 7);
		WriteChar(19, 13, "���", 7);
		WriteChar(23, 13, "��������", 7);
		WriteChar(19, 30, "��", 7);
		WriteChar(20, 30, "ESC", 5);
		WriteChar(22, 30, "������", 7);
		WriteChar(27, 30, "�س���", 5);
		WriteChar(30, 30, "ȷ��", 7);
		WriteChar(34, 30, "��ѡ�����:", 7);
		WriteChar(19, 15, "1", 7);
		WriteChar(19, 17, "2", 7);
		WriteChar(19, 19, "3", 7);
		WriteChar(19, 21, "4", 7);
		WriteChar(19, 23, "5", 7);
		WriteChar(19, 25, "6", 7);
		WriteChar(19, 27, "7", 7);
		int tem = 0;
		bool sure = false;
		for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
		{

			if (i < gRCount)
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
				if (i == sub)
				{
					WriteChar(23, 15 + tem, *(gPRecordName + i), 9);
				}
				else {
					WriteChar(23, 15 + tem, *(gPRecordName + i), 7);
				}
				if (del == i)
				{
					WriteChar(34, 15 + tem, "ɾ��", 9);
				}
				else
				{
					WriteChar(34, 15 + tem, "ɾ��", 7);
				}

			}
			else
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
			}
			tem += 2;
		}
		tem = 0;
		
		if (page == 1)
		{
			WriteChar(28, 12, "��", 4);

		}
		else
		{
			WriteChar(28, 12, "<<", 4);
		}
		if (page == n)
		{
			WriteChar(32, 12, "��", 4);
		}
		else
		{
			WriteChar(32, 12, ">>", 4);
		}
		int code = MessageListener();
		if (page == 1)
		{
			WriteChar(28, 12, "��", 4);
		}
		else
		{
			WriteChar(28, 12, "<<", 4);
			if (MousePos.X >= 56 && MousePos.X <= 58 && MousePos.Y == 12)
			{
				for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
				{
					WriteChar(23, 15 + tem, "                                 ", 7);
					tem += 2;
				}
				page--;
				tem = 0;
			}
		}
		if (page == n)
		{
			WriteChar(32, 12, "��", 4);
		}
		else
		{
			WriteChar(32, 12, ">>", 4);
			if (MousePos.X >= 64 && MousePos.X <= 66 && MousePos.Y == 12)
			{
				for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
				{
					WriteChar(23, 15 + tem, "                                 ", 7);
					tem += 2;
				}
				page++;
				tem = 0;
			}
		}
		if (code >= 1 && code <= 7)
		{
			sub = (page - 1) * 7 + code - 1;
			sure = true;
		}
		else if (code == 27)
		{
			stat = false;
		}
		else if (code == 13)
		{
			sure = true;
			stat = false;
		}
		code = 0;
		if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 15)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 0;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 0;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 17)
		{


			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 1;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 1;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 19)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 2;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 2;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 21)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 3;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 3;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 23)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 4;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 4;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 25)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 5;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 5;
				del = -1;
			}
		}
		else if (MousePos.X >= 38 && MousePos.X <= 82 && MousePos.Y == 25)
		{

			if (MousePos.X >= 68)
			{
				del = (page - 1) * 7 + 6;
				sub = -1;
			}
			else
			{
				sub = (page - 1) * 7 + 6;
				del = -1;
			}
		}
		else if (MousePos.X >= 40 && MousePos.X <= 50 && MousePos.Y == 30)
		{
			stat = false;
			MousePos = { 0,0 };
		}
		else if (MousePos.X >= 52 && MousePos.X <= 60 && MousePos.Y == 30)
		{
			sure = true;
			MousePos = { 0,0 };
		}
		else
		{
			sub = -1;
			del = -1;
		}
		if (sure)
		{
			if (del >= 0)
			{
				ClearFile(*(gPRecordName + del), 1);
				DeleteName(1, del);
				SaveName();
				ReadName();

			}
			else if (sub >= 0)
			{
				if (sub < gRCount)
				{
					ReadRecord(*(gPRecordName + sub));					
					return true;
				}
			}

		}

		for (int i = (page - 1) * 7; i < 7 + (page - 1) * 7; i++)
		{

			if (i < gRCount)
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
				if (i == sub)
				{
					WriteChar(23, 15 + tem, *(gPRecordName + i), 9);
				}
				else {
					WriteChar(23, 15 + tem, *(gPRecordName + i), 7);
				}
				if (del == i)
				{
					WriteChar(34, 15 + tem, "ɾ��", 9);
				}
				else
				{
					WriteChar(34, 15 + tem, "ɾ��", 7);
				}

			}
			else
			{
				WriteChar(23, 15 + tem, "                                 ", 9);
			}
			tem += 2;
		}
		tem = 0;


	}
	system("cls");
	return false;
}
