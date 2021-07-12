#pragma once
#ifndef _CBACKARRAY_
#define _CBACKARRAY_
#include"sys.h"
#include"PlayerChess.h"
class CBackArray
{
public:
	int ChessBoard[15][15];//棋盘，0表示没有子，1表棋手白棋的子，2表示电脑黑棋的子
	//后面可能新增人人对阵。1表示白棋落子，2表示黑棋落子
public:
	CBackArray(void);
	~CBackArray(void);
public:
	void InitBackArray();
	void UpdataChessBoard(list<CPlayerChess*> PlayerList);//函数在ChessCtrl中，并没用上
	//
};

#endif