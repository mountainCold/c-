#pragma once
/*#include "Data.h"*/
#include "Logic.h"
class Bullet
{
public:
	Bullet();
	~Bullet();
	/*��ͼ*/
	bool DrawObj();
	/*����ƶ��ۼ�*/
	bool ClearObj();
	/*�ӵ���ײ���*/
	int BulletCollisionDetection();
public:
	char dir; //����
	int sign; //��־��
	int x; //����
	int y; //����
	int Grade;//�ӵ���ǿ��
	const char* v;//�ӵ�����״
};
extern Bullet b4;
extern Bullet b5;
extern Bullet b6;
extern Bullet b7;
extern Bullet b8;
extern Bullet* Pbullet[5];