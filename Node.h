#ifndef _NODE_
#define _NODE_
#include"BackArray.h"
struct Node
{
	CBackArray BackArray;//当前局面
	int PlayOrComputer;//记录该轮到谁下棋
	int Score[15][15];//当前局面得分表
	POINT point;//记录下棋的点
	int Evaluation;//局面评分表
	bool HasSon;//是否有子节点
};
#endif