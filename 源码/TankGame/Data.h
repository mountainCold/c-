#pragma once
#include<Windows.h>
#include <stdio.h>
#define  �յ� 0
#define  ��ǽ 1  //���ɴݻ��ϰ���
#define  ��ǽ 2 //�ɴݻ��ϰ���
#define  ���� 3 //�ӵ����Դ��� ̹�˲���ͨ��
#define  �ݴ� 30 //�����ڵ�����
#define  ���� 10
#define  ʳ�� 9
#define  �ҷ�̹��1 4
#define  �ҷ�̹��2 5
#define  �з�̹��1 6
#define  �з�̹��2 7
#define  �з�̹��3 8
#define  �ҷ��ӵ�1 14
#define  �ҷ��ӵ�2 15
#define  �з��ӵ�1 16
#define  �з��ӵ�2 17
#define  �з��ӵ�3 18
#define KEYDOWN(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?1:0)
extern HANDLE g_hout; //������
extern HANDLE g_hint;  //������
extern bool g_Game; //��Ϸ�߼�ѭ���ж�
extern COORD MousePos; //�����λ��
extern int gLevel;//��ǰ�ؿ���
extern int gMaxNum;//�������
extern int gContinue;//������Ϸ
extern int gMode;//��Ϸģʽ����or˫��
extern int gMCount;//Map �����ļ�����
extern int gRCount;//Record �����ļ�����
extern char(*gPMapName)[20];//��ͼ������������
extern char(*gPRecordName)[20];//�浵������������










