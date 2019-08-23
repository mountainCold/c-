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
	v ="��";
	//strcpy_s(v, 3,"��");
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
	}if (bnum == �ݴ�)
	{
		return 0;
	}
	WriteChar(x, y, v);
	Map.SetMap(x, y, sign);
	return false;
}
bool Bullet::ClearObj()
{
	if (Map.GetMapVal(x, y) < 30 && Map.GetMapVal(x, y) != ʳ��&& Map.GetMapVal(x, y) != ����)
	{
		WriteChar(x, y, "  ");
		Map.SetMap(x, y, 0);
	}
	else if (Map.GetMapVal(x, y) == ʳ��)
	{
		Map.SetMap(x, y, ʳ��);
	}
	else if (Map.GetMapVal(x, y) == ����)
	{
		Map.SetMap(x, y, ����);
	}
	else
	{
		Map.SetMap(x, y, �ݴ�);
	}
	return true;
}
int Bullet::BulletCollisionDetection()
{
	if (Map.GetMapVal(x, y) == ��ǽ)
	{
		if (sign <= 15)
		{
			PlaySound(L"sound\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		return 1;
	}
	else if (Map.GetMapVal(x, y) == ��ǽ)
	{
		PlaySound(L"sound\\��ǽ��ը.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map.SetMap(x, y, 0);
		WriteChar(x, y, "  ");
		return 1;
	}
	else if (Map.GetMapVal(x, y) == ����)
	{
		g_Game = false;
		return 1;
	}
	else if (Map.GetMapVal(x, y) == �ݴ�)
	{
		int num = Map.GetMapVal(x, y);
		num += sign;
		Map.SetMap(x, y, num);
		return �ݴ�;
	}
	else if (Map.GetMapVal(x, y) == ʳ��)
	{
		return �ݴ�;
	}
	else if (Map.GetMapVal(x, y) == ����)
	{
		return �ݴ�;
	}
	//�ӵ�����̹��
	else if (Map.GetMapVal(x, y) >= �ҷ�̹��1 && Map.GetMapVal(x, y) <= �з�̹��3)
	{
		int Tx = sign % 10;
		int Ty = Map.GetMapVal(x, y);
		// ��ͬ��Ӫ���ӵ� û���κ�Ӱ��
		if (Tx >= �ҷ�̹��1 && Tx <= �ҷ�̹��2 && Ty >= �ҷ�̹��1 && Ty <= �ҷ�̹��2 ||
			Tx >= �з�̹��1 && Tx <= �з�̹��3 && Ty >= �з�̹��1 && Ty <= �з�̹��3)
		{
			return 0;
		}
		// ��ͬ��Ӫ�ӵ�
		else
		{
			PlaySound(L"sound\\���б�ը.wav", NULL, SND_FILENAME | SND_ASYNC);
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
	//�ӵ������ӵ�
	else if (Map.GetMapVal(x, y) >= �ҷ��ӵ�1 && Map.GetMapVal(x, y) <= �з��ӵ�3)
	{
		int Bx = sign;
		int By = Map.GetMapVal(x, y);
		//ͬ��Ӫ
		if (Bx >= �ҷ��ӵ�1 && Bx <= �ҷ��ӵ�2 && By >= �ҷ��ӵ�1 && By <= �ҷ��ӵ�2 ||
			Bx >= �з��ӵ�1 && Bx <= �з��ӵ�3 && By >= �з��ӵ�1 && By <= �з��ӵ�3)
		{
			return 0;
		}
		//��ͬ��Ӫ
		else
		{
			PlaySound(L"sound\\�ڵ���ը.wav", NULL, SND_FILENAME | SND_ASYNC);
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
	//�����ݴԹ�
	else if (Map.GetMapVal(x,y) > �ݴ�)
	{
		int Mnum = Map.GetMapVal(x, y) - �ݴ�;
		if (Mnum >= �ҷ�̹��1 && Mnum <= �з�̹��3)
		{

			int sx = sign % 10;
			// ��ͬ��Ӫ��̹�� û���κ�Ӱ��
			if (sx >= �ҷ�̹��1 && sx <= �ҷ�̹��2 && Mnum >= �ҷ�̹��1 && Mnum <= �ҷ�̹��2 ||
				sx >= �з�̹��1 && sx <= �з�̹��3 && Mnum >= �з�̹��1 && Mnum <= �з�̹��3)
			{
				return �ݴ�;
			}
			// ��ͬ��Ӫ̹��
			else
			{
				PlaySound(L"sound\\���б�ը.wav", NULL, SND_FILENAME | SND_ASYNC);
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
		//�ӵ������ӵ�
		if (Map.GetMapVal(x,y) >= �ҷ��ӵ�1 && Map.GetMapVal(x, y) <= �з��ӵ�3)
		{
			int sx = sign;
			//ͬ��Ӫ
			if (sx >= �ҷ��ӵ�1 && sx <= �ҷ��ӵ�2 && Mnum >= �ҷ��ӵ�1 && Mnum <= �ҷ��ӵ�2 ||
				sx >= �з��ӵ�1 && sx <= �з��ӵ�3 && Mnum >= �з��ӵ�1 && Mnum <= �з��ӵ�3)
			{
				return �ݴ�;
			}
			//��ͬ��Ӫ
			else
			{
				PlaySound(L"sound\\�ڵ���ը.wav", NULL, SND_FILENAME | SND_ASYNC);
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