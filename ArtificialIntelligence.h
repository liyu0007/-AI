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
	virtual POINT CreateChess(CBackArray BackArray)=0;//根据当前局面确定下棋点
//*****************************************************************
//实现初级难度的变量和函数，以后可能改成和中高级统一的形式
public:         
	int Score[15][15];//得分表
public:
	POINT FindMax(int score[15][15]);
public:
	CountNumber CountNum(int,int,int,int,int);//统计五个数里有几个1和2
	void GetScore(CBackArray BackArray,int num,int Score[15][15]);
	void InitScore(int Score[15][15]);
//*********************************************************************
//**中高级难度************************************//
public:
	void Evaluation(Node& node);//对一个局面的估值函数
	POINT FindSecondMax(int score[15][15]);//找到第二好的点
	//////***设计上的失误，导致这个函数没用上*******************************//////
	POINT FindThirdMax(int score[15][15]);//第三好的点
	//////*************************************////////////
	bool PlayerWinGame(CBackArray BackArray);//1表示人赢了 0表示计算机赢
	bool ComputerWinGame(CBackArray BackArray);
	void CreateTree(CBackArray BackArray,int depth);//创建博弈树,深度depth
	POINT MaxMinSearch(int depth); //极大极小值搜索,深度depth
	int MaxMin(int first,int second,int third,int fourth,int fifth,int playerorcomputer);
	void DeleteTree();
public:
	vector<Node*> Tree;//完全N叉树用数组表示，N暂定为5，5叉树
	int TreeDepth;
};
#endif