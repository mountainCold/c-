#include "Tank.h"
#include "MapTank.h"
#include "Bullet.h"
#include <time.h>
Tank t4;
Tank t5;
Tank t6;
Tank t7;
Tank t8;
Tank* Ptank[5] = { &t4,&t5,&t6,&t7,&t8 };
Tank::Tank()
{
	bulletStat = 1;
	sign = x;
	heart = heart;
	dir = 's';
	x = 2;
	y = 2;
	bull.sign = 16;
}
Tank::Tank(int x, int het)
{
	SetTank(x, het);
}
void Tank::SetTank(int si, int het)
{
	bulletStat = 1;
	sign = si;
	heart = het;
	if (si == 4)
	{
		dir = 'w';
		x = 26;
		y = 47;
		bull.sign = 14;

	}
	else if (si == 5)
	{
		dir = 'w';
		x = 33;
		y = 47;
		bull.sign = 15;
	}
	else if (si == 6)
	{
		dir = 's';
		x = 2;
		y = 2;
		bull.sign = 16;
	}
	else if (si == 7)
	{
		dir = 's';
		x = 29;
		y = 2;
		bull.sign = 17;
	}
	else if (si == 8)
	{
		dir = 's';
		x = 57;
		y = 2;
		bull.sign = 18;
	}
	bull.dir = dir;
	n_path.clear();
	
}
Tank::~Tank()
{
}
bool Tank::DrawObj()
{
	if (heart <= 0)
	{
		return false;
	}
	int color = sign;
	for (int i = x - 1; i < x + 2; i++)
	{
		for (int j = y - 1; j < y + 2; j++)
		{
			if (Map.GetMapVal(i, j) < 30)
			{
				Map.SetMap(i, j, sign);
			}
		}
	}
	switch (dir)
	{
	case 'w':
	{
		bull.x = x;
		bull.y = y - 1;
		if (Map.GetMapVal(x - 1, y - 1) < 30)
		{
			WriteChar(x - 1, y - 1, "  ", color);
		}
		if (Map.GetMapVal(x + 1, y - 1) < 30)
		{
			WriteChar(x + 1, y - 1, "  ", color);
		}
		if (Map.GetMapVal(x, y - 1) < 30)
		{
			WriteChar(x, y - 1, "◆", color);
		}
		if (Map.GetMapVal(x, y) < 30)
		{
			WriteChar(x, y, "⊙", 7);
		}
		if (Map.GetMapVal(x - 1, y) < 30)
		{
			WriteChar(x - 1, y, "■", color);
		}
		if (Map.GetMapVal(x + 1, y) < 30)
		{
			WriteChar(x + 1, y, "■", color);
		}
		if (Map.GetMapVal(x - 1, y + 1) < 30)
		{
			WriteChar(x - 1, y + 1, "■", color);
		}
		if (Map.GetMapVal(x + 1, y + 1) < 30)
		{
			WriteChar(x + 1, y + 1, "■", color);
		}
		if (Map.GetMapVal(x, y + 1) < 30)
		{
			WriteChar(x, y + 1, "  ", color);
		}

	}break;
	case 's':
	{

		bull.x = x;
		bull.y = y + 1;


		if (Map.GetMapVal(x - 1, y + 1) < 30)
		{
			WriteChar(x - 1, y + 1, "  ", color);
		}
		if (Map.GetMapVal(x + 1, y + 1) < 30)
		{
			WriteChar(x + 1, y + 1, "  ", color);
		}
		if (Map.GetMapVal(x, y + 1) < 30)
		{
			WriteChar(x, y + 1, "◆", color);
		}
		if (Map.GetMapVal(x, y) < 30)
		{
			WriteChar(x, y, "⊙");
		}
		if (Map.GetMapVal(x - 1, y) < 30)
		{
			WriteChar(x - 1, y, "■", color);
		}
		if (Map.GetMapVal(x + 1, y) < 30)
		{
			WriteChar(x + 1, y, "■", color);
		}
		if (Map.GetMapVal(x - 1, y - 1) < 30)
		{
			WriteChar(x - 1, y - 1, "■", color);
		}
		if (Map.GetMapVal(x + 1, y - 1) < 30)
		{
			WriteChar(x + 1, y - 1, "■", color);
		}
		if (Map.GetMapVal(x, y - 1) < 30)
		{
			WriteChar(x, y - 1, "  ", color);
		}

	}break;
	case 'a':
	{

		bull.x = x - 1;
		bull.y = y;

		if (Map.GetMapVal(x - 1, y + 1) < 30)
		{
			WriteChar(x - 1, y + 1, "  ", color);
		}
		if (Map.GetMapVal(x - 1, y - 1) < 30)
		{
			WriteChar(x - 1, y - 1, "  ", color);
		}
		if (Map.GetMapVal(x - 1, y) < 30)
		{
			WriteChar(x - 1, y, "◆", color);
		}
		if (Map.GetMapVal(x, y) < 30)
		{
			WriteChar(x, y, "⊙");
		}
		if (Map.GetMapVal(x, y + 1) < 30)
		{
			WriteChar(x, y + 1, "■", color);
		}
		if (Map.GetMapVal(x, y - 1) < 30)
		{
			WriteChar(x, y - 1, "■", color);
		}
		if (Map.GetMapVal(x + 1, y + 1) < 30)
		{
			WriteChar(x + 1, y + 1, "■", color);
		}
		if (Map.GetMapVal(x + 1, y - 1) < 30)
		{
			WriteChar(x + 1, y - 1, "■", color);
		}
		if (Map.GetMapVal(x + 1, y )< 30)
		{
			WriteChar(x + 1, y, "  ", color);
		}


	}break;
	case 'd':
	{

		bull.x = x + 1;
		bull.y = y;
		if (Map.GetMapVal(x + 1, y + 1) < 30)
		{
			WriteChar(x + 1, y + 1, "  ", color);
		}
		if (Map.GetMapVal(x + 1, y - 1) < 30)
		{
			WriteChar(x + 1, y - 1, "  ", color);
		}
		if (Map.GetMapVal(x + 1, y) < 30)
		{
			WriteChar(x + 1, y, "◆", color);
		}
		if (Map.GetMapVal(x, y) < 30)
		{
			WriteChar(x, y, "⊙");
		}
		if (Map.GetMapVal(x, y + 1) < 30)
		{
			WriteChar(x, y + 1, "■", color);
		}
		if (Map.GetMapVal(x, y - 1) < 30)
		{
			WriteChar(x, y - 1, "■", color);
		}
		if (Map.GetMapVal(x - 1, y + 1) < 30)
		{
			WriteChar(x - 1, y + 1, "■", color);
		}
		if (Map.GetMapVal(x - 1, y - 1) < 30)
		{
			WriteChar(x - 1, y - 1, "■", color);
		}
		if (Map.GetMapVal(x - 1, y) < 30)
		{
			WriteChar(x - 1, y, "  ", color);
		}

	}break;
	default:
		break;
	}
	bull.dir = dir;
	return true;
}
bool Tank::ClearObj()
{
	int color = 0;
	switch (dir)
	{
	case 'w':
	{

		if (Map.GetMapVal(x - 1, y + 2) < 30)
		{
			Map.SetMap(x - 1, y + 2, 0);
			WriteChar(x - 1, y + 2, "  ", color);
		}
		else
		{
			Map.SetMap(x - 1, y + 2, 草丛);
		}
		if (Map.GetMapVal(x + 1, y + 2) < 30)
		{
			Map.SetMap(x + 1, y + 2, 0);
			WriteChar(x + 1, y + 2, "  ", color);
		}
		else
		{
			Map.SetMap(x + 1, y + 2, 草丛);
		}
		if (Map.GetMapVal(x, y + 2) < 30)
		{
			Map.SetMap(x, y + 2, 0);
			WriteChar(x, y + 2, "  ", color);
		}
		else
		{
			Map.SetMap(x, y + 2, 草丛);

		}


	}break;
	case 'a':
	{
		if (Map.GetMapVal(x + 2, y - 1) < 30)
		{
			Map.SetMap(x + 2, y - 1, 0);
			WriteChar(x + 2, y - 1, "  ", color);
		}
		else
		{
			Map.SetMap(x + 2, y - 1, 草丛);
		}
		if (Map.GetMapVal(x + 2, y + 1) < 30)
		{
			Map.SetMap(x + 2, y + 1, 0);
			WriteChar(x + 2, y + 1, "  ", color);
		}
		else
		{
			Map.SetMap(x + 2, y + 1, 草丛);
		}
		if (Map.GetMapVal(x + 2, y) < 30)
		{
			Map.SetMap(x + 2, y, 0);
			WriteChar(x + 2, y, "  ", color);
		}
		else
		{
			Map.SetMap(x + 2, y, 草丛);

		}

	}break;
	case 's':
	{
		if (Map.GetMapVal(x - 1, y - 2) < 30)
		{
			Map.SetMap(x - 1, y - 2, 0);
			WriteChar(x - 1, y - 2, "  ", color);
		}
		else
		{
			Map.SetMap(x - 1, y - 2, 草丛);
		}
		if (Map.GetMapVal(x + 1, y - 2) < 30)
		{
			Map.SetMap(x + 1, y - 2, 0);
			WriteChar(x + 1, y - 2, "  ", color);
		}
		else
		{
			Map.SetMap(x + 1, y - 2, 草丛);
		}
		if (Map.GetMapVal(x, y - 2) < 30)
		{
			Map.SetMap(x, y - 2, 0);
			WriteChar(x, y - 2, "  ", color);
		}
		else
		{
			Map.SetMap(x, y - 2, 草丛);

		}

	}break;
	case 'd':
	{
		if (Map.GetMapVal(x - 2, y - 1) < 30)
		{
			Map.SetMap(x - 2, y - 1, 0);
			WriteChar(x - 2, y - 1, "  ", color);
		}
		else
		{
			Map.SetMap(x - 2, y - 1, 草丛);
		}
		if (Map.GetMapVal(x - 2, y + 1) < 30)
		{
			Map.SetMap(x - 2, y + 1, 0);
			WriteChar(x - 2, y + 1, "  ", color);
		}
		else
		{
			Map.SetMap(x - 2, y + 1, 草丛);
		}
		if (Map.GetMapVal(x - 2, y) < 30)
		{
			Map.SetMap(x - 2, y, 0);
			WriteChar(x - 2, y, "  ", color);
		}
		else
		{
			Map.SetMap(x - 2, y, 草丛);
		}
	}break;
	}
	return true;
}
void Tank::DelObj()
{
	for (int i = x - 1; i < x + 2; i++)
	{
		for (int j = y - 1; j < y + 2; j++)
		{
			if (Map.GetMapVal(i, j) >= 30)
			{
				Map.SetMap(i, j, 草丛);
			}
			else
			{
				WriteChar(i, j, "  ");
				Map.SetMap(i, j, 0);
			}
		}
	}
}
int Tank::TankMoveDetection()
{
	for (int i = x - 1; i < x + 2; i++)
	{
		for (int j = y - 1; j < y + 2; j++)
		{
			int mapNum = Map.GetMapVal(i, j);
			if (mapNum >= 1 && mapNum <= 8 && mapNum != sign ||
				mapNum == 10)//遇到边界移动回滚
			{
				return 1;
			}
			if (mapNum == 草丛)
			{
				mapNum += sign;
				Map.SetMap(i, j, mapNum);
			}
			if (mapNum == 食物)
			{
				mapNum = 0;
				heart += 1;
			}
		}
	}
	return 0;
}
bool Tank::OpCodeDetection(char ch)
{
	/*dir = ch;*/
	DrawObj();
	int flag = 0;
	switch (ch)
	{
	case 'w':
	{
		--y;
		if (TankMoveDetection() != 0)
		{
			flag = 1;
			++y;
		}
	}break;
	case 's':
	{
		++y;
		if (TankMoveDetection() != 0)
		{
			flag = 1;
			--y;
		}
	}break;
	case 'a':
	{
		--x;
		if (TankMoveDetection() != 0)
		{
			flag = 1;
			++x;
		}

	}break;
	case 'd':
	{
		++x;
		if (TankMoveDetection() != 0)
		{
			flag = 1;
			--x;
		}
	}break;

	default:
		flag = 1;
		break;
	}
	if (flag == 0)
	{
		if (x > 2 || y > 2 || x < 58 || y < 48)
		{
			DrawObj();
			ClearObj();
		}
		return true;
	}
	else
	{
		return false;
	}

}
void Tank::OpenFire()
{
	if (bulletStat == 1)
	{
		bulletStat = 0;
		int numT = sign - 4;
		*Pbullet[numT] = bull;
	}

}
void Tank::GetPath(int dx,int dy)
{
	ast.SetSign(sign);
	ast.getPath(x, y, dx, dy, n_path);
	step =n_path.size()-1;
}
void Tank::AutoMoveForOPPTank(int nT)
{

	if (x > 1 || y > 1 || x < 58 || y < 48)
	{
		DrawObj();
	}

	int num = 0;
	char ch = 0;
	srand(sign * (int)time(NULL));
	num = rand() % 7;
	if(n_path.size()==0)
	{
		if (num == 0)
		{
			ch = 'w';
		}
		if (num == 1 || num == 4)
		{
			ch = 's';
		}
		if (num == 2)
		{
			ch = 'a';
		}
		if (num == 3)
		{
			ch = 'd';
		}
		if (num >= 5)
		{
			OpenFire();
		}
		if (nT >= 7)
		{
			if (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd')
			{
				if (x > 1 || y > 1 || x < 58 || y < 48)
				{
					dir = ch;
					//DrawObj();

				}
			}
			OpCodeDetection(ch);
		}
	}
	else
	{
		if (num >= 5)
		{
			OpenFire();
		}
		if (nT >= 7)
		{
			if (step < 0)
			{
				return;
			}
			int px = n_path[step].x;
			int py = n_path[step].y;
			--step;
			if (x - px > 0)
			{
				ch = 'a';
			}
			else if (px - x > 0)
			{
				ch = 'd';
			}
			else
			{
				if (y - py > 0)
				{
					ch = 'w';
				}
				else if (py - y > 0)
				{
					ch = 's';
				}
			}
			dir = ch;
			//DrawObj();
			OpCodeDetection(ch);
		}
	}
	
}

int Tank::RangeSensing()
{
	int num = 0;
 	if (!danger.empty())
 	{
		danger.clear();
	}
	for (int i=x-9;i<x+10;++i)
	{
		for (int j=y-9;j<y+10;++j)
		{
			num = Map.GetMapVal(i, j);
			if (num <=30)
			{
				if (sign >= 我方坦克1 && sign <= 我方坦克2 && num >= 敌方坦克1 && num <= 敌方坦克3 ||
					sign >= 敌方坦克1 && sign <= 敌方坦克3 && num >= 我方坦克1 && num <= 我方坦克2)
				{
					return num;
				}
				if (sign >= 我方坦克1 && sign <= 我方坦克2 && num >= 敌方子弹1 && num <= 敌方子弹3 ||
					sign >= 敌方坦克1 && sign <= 敌方坦克3 && num >= 我方子弹1 && num <= 我方子弹2)
				{
					for (int i = 0; i < 5; ++i)
					{
						if (Pbullet[i]->sign == num)
						{
							danger.push_back(*Pbullet[i]);
						}
					}
				}
			}
			else //遇到草丛怪
			{
				num -= 30;
				if (sign >= 我方坦克1 && sign <= 我方坦克2 && num >= 敌方坦克1 && num <= 敌方坦克3 ||
					sign >= 敌方坦克1 && sign <= 敌方坦克3 && num >= 我方坦克1 && num <= 我方坦克2)
				{
					return num;
				}
				if (sign >= 我方坦克1 && sign <= 我方坦克2 && num >= 敌方子弹1 && num <= 敌方子弹3 ||
					sign >= 敌方坦克1 && sign <= 敌方坦克3 && num >= 我方子弹1 && num <= 我方子弹2)
				{
					for (int i = 0; i < 5; ++i)
					{
						if (Pbullet[i]->sign == num)
						{
							danger.push_back(*Pbullet[i]);
						}
					}
				}
			}
			
		}
	}
	return 0;
}

int Tank::DodgeBullet()
{
	int num = danger.size();
	if (num ==0)
	{
		return 0;
	}
	char ch = 0;
	for (int i=0;i<num;++i)
	{
		ch = danger[i].dir;
		switch (ch)
		{
		case 'w':
		{
			if (danger[i].y>y)
			{
				
				if (danger[i].x == x - 1)
				{
					if (danger[i].y - y <= 3)
					{
						dir = 'd';
						if (OpCodeDetection('d'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
										
				}
				else if (danger[i].x == x + 1)
				{
					if (danger[i].y - y <= 3)
					{
						dir = 'a';
						if (OpCodeDetection('a'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					
				}
				else if(danger[i].x == x)
				{
					if (danger[i].y-y>=6)
					{
						if (Map.GetMapVal(x - 2, y) == 0 || Map.GetMapVal(x - 2, y) == 草丛)
						{
							dir = 'a';
							if (OpCodeDetection('a'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
						else if (Map.GetMapVal(x + 2, y) == 0 || Map.GetMapVal(x + 2, y) == 草丛)
						{
							dir = 'd';
							if (OpCodeDetection('d'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
					}
					
				}
				
			}
			
		}break;
		case 's':
		{
			if (danger[i].y<y)
			{

				if (danger[i].x == x - 1)
				{
					if (y-danger[i].y<=3)
					{
						dir = 'd';
						if (OpCodeDetection('d'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					
				}
				else if (danger[i].x == x + 1)
				{
					if (y - danger[i].y <= 3)
					{
						dir = 'a';
						if (OpCodeDetection('a'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					
				}
				else if (danger[i].x == x)
				{
					if (y-danger[i].y>=6)
					{
						if (Map.GetMapVal(x - 2, y) == 0 || Map.GetMapVal(x - 2, y) == 草丛)
						{
							dir = 'a';
							if (OpCodeDetection('a'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
						else if (Map.GetMapVal(x + 2, y) == 0 || Map.GetMapVal(x + 2, y) == 草丛)
						{
							dir = 'd';
							if (OpCodeDetection('d'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
					}
					
				}
			}
			
		}break;
		case 'a':
		{
			if (danger[i].x> x)
			{
				if (danger[i].y == y - 1)
				{
					if (danger[i].x-x<=3)
					{
						dir = 's';
						if (OpCodeDetection('s'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					
				}
				else if (danger[i].y == y + 1)
				{
					if (danger[i].x - x <= 3)
					{
						dir = 'w';
						if (OpCodeDetection('w'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					
				} 
				else if (danger[i].y == y)
				{
					if (danger[i].x-x>=6)
					{
						if (Map.GetMapVal(x, y + 2) == 0 || Map.GetMapVal(x, y + 2) == 草丛)
						{
							dir = 's';
							if (OpCodeDetection('s'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
						else if (Map.GetMapVal(x, y - 2) == 0 || Map.GetMapVal(x, y - 2) == 草丛)
						{
							dir = 'w';
							if (OpCodeDetection('w'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
					}
					
				}
			}
			
		}break; 
		case 'd':
		{
			if (danger[i].x < x)
			{
				if (danger[i].y == y - 1)
				{
					if (x - danger[i].x <= 3)
					{
						dir = 's';
						if (OpCodeDetection('s'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
				}
				else if (danger[i].y == y + 1)
				{
					if (x - danger[i].x <= 3)
					{
						dir = 'w';
						if (OpCodeDetection('w'))
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}

				}
				else if (danger[i].y == y)
				{
					if (x - danger[i].x >= 6)
					{
						if (Map.GetMapVal(x, y + 2) == 0 || Map.GetMapVal(x, y + 2) == 草丛)
						{
							dir = 's';
							if (OpCodeDetection('s'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
						else if (Map.GetMapVal(x, y - 2) == 0 || Map.GetMapVal(x, y - 2) == 草丛)
						{
							dir = 'w';
							if (OpCodeDetection('w'))
							{
								return 1;
							}
							else
							{
								return 0;
							}
						}
					}

				}
			}
			
			
		}break;
		default:
			break;
		}
	}
	return 0;
}



