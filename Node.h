#ifndef _NODE_
#define _NODE_
#include"BackArray.h"
struct Node
{
	CBackArray BackArray;//��ǰ����
	int PlayOrComputer;//��¼���ֵ�˭����
	int Score[15][15];//��ǰ����÷ֱ�
	POINT point;//��¼����ĵ�
	int Evaluation;//�������ֱ�
	bool HasSon;//�Ƿ����ӽڵ�
};
#endif