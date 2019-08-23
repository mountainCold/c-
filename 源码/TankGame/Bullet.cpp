#include "Bullet.h"
#include "MapTank.h"
#include "Tank.h"
#include <string.h>
#include "Data.h"
Bullet b4;
Bullet b5;
Bullet b6;
Bullet b7;
Bullet b8;
Bullet* Pbullet[5] = { &b4,&b5,&b6,&b7,&b8 };
Bullet::Bullet()
{
	Grade = 1;
	v ="○";
	//strcpy_s(v, 3,"○");
}
Bullet::~Bullet() {}
bool Bullet::DrawObj() {
	if (x > 58 || x < 1 || y > 48 || y < 1)
	{
		return true;
	}
	ClearObj();
	switch (dir)
	{
	case 'w':
	{
		--y;
	}break;
	case 's':
	{
		++y;
	}break;
	case 'a':
	{
		--x;

	}break;
	case 'd':
	{
		++x;
	}break;
	default:
		break;
	}
	int bnum = BulletCollisionDetection();
	if (bnum == 1)
	{
		return 1;
	}if (bnum == 草丛)
	{
		return 0;
	}
	WriteChar(x, y, v);
	Map.SetMap(x, y, sign);
	return false;
}
bool Bullet::ClearObj()
{
	if (Map.GetMapVal(x, y) < 30 && Map.GetMapVal(x, y) != 食物&& Map.GetMapVal(x, y) != 河流)
	{
		WriteChar(x, y, "  ");
		Map.SetMap(x, y, 0);
	}
	else if (Map.GetMapVal(x, y) == 食物)
	{
		Map.SetMap(x, y, 食物);
	}
	else if (Map.GetMapVal(x, y) == 河流)
	{
		Map.SetMap(x, y, 河流);
	}
	else
	{
		Map.SetMap(x, y, 草丛);
	}
	return true;
}
int Bullet::BulletCollisionDetection()
{
	if (Map.GetMapVal(x, y) == 铁墙)
	{
		if (sign <= 15)
		{
			PlaySound(L"sound\\触界.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		return 1;
	}
	else if (Map.GetMapVal(x, y) == 土墙)
	{
		PlaySound(L"sound\\土墙爆炸.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map.SetMap(x, y, 0);
		WriteChar(x, y, "  ");
		return 1;
	}
	else if (Map.GetMapVal(x, y) == 基地)
	{
		g_Game = false;
		return 1;
	}
	else if (Map.GetMapVal(x, y) == 草丛)
	{
		int num = Map.GetMapVal(x, y);
		num += sign;
		Map.SetMap(x, y, num);
		return 草丛;
	}
	else if (Map.GetMapVal(x, y) == 食物)
	{
		return 草丛;
	}
	else if (Map.GetMapVal(x, y) == 河流)
	{
		return 草丛;
	}
	//子弹遇到坦克
	else if (Map.GetMapVal(x, y) >= 我方坦克1 && Map.GetMapVal(x, y) <= 敌方坦克3)
	{
		int Tx = sign % 10;
		int Ty = Map.GetMapVal(x, y);
		// 是同阵营的子弹 没有任何影响
		if (Tx >= 我方坦克1 && Tx <= 我方坦克2 && Ty >= 我方坦克1 && Ty <= 我方坦克2 ||
			Tx >= 敌方坦克1 && Tx <= 敌方坦克3 && Ty >= 敌方坦克1 && Ty <= 敌方坦克3)
		{
			return 0;
		}
		// 不同阵营子弹
		else
		{
			PlaySound(L"sound\\命中爆炸.wav", NULL, SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < 5; i++)
			{
				if ((*Ptank[i]).sign == Map.GetMapVal(x, y))
				{
					(*Ptank[i]).DelObj();
 					if ((*Ptank[i]).bulletStat == 0)
 					{
 						(*Pbullet[i]).ClearObj();
 					}
					(*Ptank[i]).heart--;
					if ((*Ptank[i]).heart > 0)
					{
						(*Ptank[i]).SetTank((*Ptank[i]).sign, (*Ptank[i]).heart);
					}
					else
					{
						(*Ptank[i]).SetTank((*Ptank[i]).sign, 0);
					}
				}
			}
			return 1;
		}
	}
	//子弹遇到子弹
	else if (Map.GetMapVal(x, y) >= 我方子弹1 && Map.GetMapVal(x, y) <= 敌方子弹3)
	{
		int Bx = sign;
		int By = Map.GetMapVal(x, y);
		//同阵营
		if (Bx >= 我方子弹1 && Bx <= 我方子弹2 && By >= 我方子弹1 && By <= 我方子弹2 ||
			Bx >= 敌方子弹1 && Bx <= 敌方子弹3 && By >= 敌方子弹1 && By <= 敌方子弹3)
		{
			return 0;
		}
		//不同阵营
		else
		{
			PlaySound(L"sound\\炮弹爆炸.wav", NULL, SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < 5; i++)
			{
				if ((*Pbullet[i]).sign == By)
				{

					(*Pbullet[i]).ClearObj();
					(*Ptank[i]).bulletStat = 1;
				}
			}
			ClearObj();
			return 1;
		}

	}
	//遇到草丛怪
	else if (Map.GetMapVal(x,y) > 草丛)
	{
		int Mnum = Map.GetMapVal(x, y) - 草丛;
		if (Mnum >= 我方坦克1 && Mnum <= 敌方坦克3)
		{

			int sx = sign % 10;
			// 是同阵营的坦克 没有任何影响
			if (sx >= 我方坦克1 && sx <= 我方坦克2 && Mnum >= 我方坦克1 && Mnum <= 我方坦克2 ||
				sx >= 敌方坦克1 && sx <= 敌方坦克3 && Mnum >= 敌方坦克1 && Mnum <= 敌方坦克3)
			{
				return 草丛;
			}
			// 不同阵营坦克
			else
			{
				PlaySound(L"sound\\命中爆炸.wav", NULL, SND_FILENAME | SND_ASYNC);
				for (int i = 0; i < 6; i++)
				{
					if ((*Ptank[i]).sign == Mnum)
					{
						(*Ptank[i]).DelObj();
						if ((*Ptank[i]).bulletStat == 0)
						{
							(*Pbullet[i]).ClearObj();
						}
						(*Ptank[i]).heart--;
						if ((*Ptank[i]).heart > 0)
						{
							(*Ptank[i] ).SetTank((*Ptank[i]).sign, (*Ptank[i]).heart);
						}
						else
						{

							(*Ptank[i]).SetTank((*Ptank[i]).sign, 0);
						}
						return 1;
					}

				}

				return 1;
			}
		}
		//子弹遇到子弹
		if (Map.GetMapVal(x,y) >= 我方子弹1 && Map.GetMapVal(x, y) <= 敌方子弹3)
		{
			int sx = sign;
			//同阵营
			if (sx >= 我方子弹1 && sx <= 我方子弹2 && Mnum >= 我方子弹1 && Mnum <= 我方子弹2 ||
				sx >= 敌方子弹1 && sx <= 敌方子弹3 && Mnum >= 敌方子弹1 && Mnum <= 敌方子弹3)
			{
				return 草丛;
			}
			//不同阵营
			else
			{
				PlaySound(L"sound\\炮弹爆炸.wav", NULL, SND_FILENAME | SND_ASYNC);
				for (int i = 0; i < 5; i++)
				{
					if ((*Pbullet[i]).sign == Mnum)
					{

						(*Pbullet[i]).ClearObj();
						(*Ptank[i]).bulletStat = 1;
					}

				}
				ClearObj();
				return 1;
			}

		}
	}
	else {
		return 0;
	}
	return 0;
}