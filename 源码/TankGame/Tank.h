#pragma once
/*#include "Data.h"*/

#include "Bullet.h"
#include "Logic.h"
#include <iosfwd>
#include "AStar.h"

class Tank
{
public:
	Tank();
	Tank(int x, int het = 3);
	~Tank();
	/*打印坦克*/
	bool DrawObj();
	/*清除移动痕迹*/
	bool ClearObj();
	/*删除坦克*/
	void DelObj();
	/*初始化坦克*/
	void SetTank(int x,int het=3);
	/*坦克移动检测*/
	int TankMoveDetection();
	/*方向判定*/
	bool OpCodeDetection(char ch);
	/*发射子弹*/
	void OpenFire();
	void GetPath(int dx=26,int dy=47);
	/*自动寻路*/
	void AutoMoveForOPPTank(int nT);
	/*范围检测*/
	int RangeSensing();
	/*自动躲子弹
	1 要求：子弹和坦克的距离 各自的移动速度
	*/
	int DodgeBullet();
public:
	char dir; //方向
	int sign; //标志符
	int x; //坐标
	int y; //坐标
	int heart;//坦克的生命值
	int bulletStat; //子弹的状态 是否发射
	Bullet bull;
	vector<Point> n_path; //自动路径
	Astar ast;
private:
	int step;
	vector<Bullet> danger;

};
extern Tank t4;
extern Tank t5;
extern Tank t6;
extern Tank t7;
extern Tank t8;
extern Tank* Ptank[5];