#pragma once
#ifndef _CARTINT_
#define _CARTINT_
#include"sys.h"
#include"BackArray.h"
#include"CountNum.h"
#include"Node.h"
class CArtificialIntelligence
{
public:
	CArtificialIntelligence(int depth);
	~CArtificialIntelligence(void);
public:
	virtual POINT CreateChess(CBackArray BackArray)=0;//���ݵ�ǰ����ȷ�������
//*****************************************************************
//ʵ�ֳ����Ѷȵı����ͺ������Ժ���ܸĳɺ��и߼�ͳһ����ʽ
public:         
	int Score[15][15];//�÷ֱ�
public:
	POINT FindMax(int score[15][15]);
public:
	CountNumber CountNum(int,int,int,int,int);//ͳ����������м���1��2
	void GetScore(CBackArray BackArray,int num,int Score[15][15]);
	void InitScore(int Score[15][15]);
//*********************************************************************
//**�и߼��Ѷ�************************************//
public:
	void Evaluation(Node& node);//��һ������Ĺ�ֵ����
	POINT FindSecondMax(int score[15][15]);//�ҵ��ڶ��õĵ�
	//////***����ϵ�ʧ�󣬵����������û����*******************************//////
	POINT FindThirdMax(int score[15][15]);//�����õĵ�
	//////*************************************////////////
	bool PlayerWinGame(CBackArray BackArray);//1��ʾ��Ӯ�� 0��ʾ�����Ӯ
	bool ComputerWinGame(CBackArray BackArray);
	void CreateTree(CBackArray BackArray,int depth);//����������,���depth
	POINT MaxMinSearch(int depth); //����Сֵ����,���depth
	int MaxMin(int first,int second,int third,int fourth,int fifth,int playerorcomputer);
	void DeleteTree();
public:
	vector<Node*> Tree;//��ȫN�����������ʾ��N�ݶ�Ϊ5��5����
	int TreeDepth;
};
#endif