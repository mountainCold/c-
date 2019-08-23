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
	/*��ӡ̹��*/
	bool DrawObj();
	/*����ƶ��ۼ�*/
	bool ClearObj();
	/*ɾ��̹��*/
	void DelObj();
	/*��ʼ��̹��*/
	void SetTank(int x,int het=3);
	/*̹���ƶ����*/
	int TankMoveDetection();
	/*�����ж�*/
	bool OpCodeDetection(char ch);
	/*�����ӵ�*/
	void OpenFire();
	void GetPath(int dx=26,int dy=47);
	/*�Զ�Ѱ·*/
	void AutoMoveForOPPTank(int nT);
	/*��Χ���*/
	int RangeSensing();
	/*�Զ����ӵ�
	1 Ҫ���ӵ���̹�˵ľ��� ���Ե��ƶ��ٶ�
	*/
	int DodgeBullet();
public:
	char dir; //����
	int sign; //��־��
	int x; //����
	int y; //����
	int heart;//̹�˵�����ֵ
	int bulletStat; //�ӵ���״̬ �Ƿ���
	Bullet bull;
	vector<Point> n_path; //�Զ�·��
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