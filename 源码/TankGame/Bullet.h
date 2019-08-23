#pragma once
/*#include "Data.h"*/
#include "Logic.h"
class Bullet
{
public:
	Bullet();
	~Bullet();
	/*画图*/
	bool DrawObj();
	/*清除移动痕迹*/
	bool ClearObj();
	/*子弹碰撞检测*/
	int BulletCollisionDetection();
public:
	char dir; //方向
	int sign; //标志符
	int x; //坐标
	int y; //坐标
	int Grade;//子弹的强度
	const char* v;//子弹的形状
};
extern Bullet b4;
extern Bullet b5;
extern Bullet b6;
extern Bullet b7;
extern Bullet b8;
extern Bullet* Pbullet[5];