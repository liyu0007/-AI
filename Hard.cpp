#include "Hard.h"


CHard::CHard(void):CArtificialIntelligence(8)
{
	TreeDepth = 8;
}


CHard::~CHard(void)
{
}


POINT CHard::CreateChess(CBackArray BackArray)
{
	POINT pointTemp = {0};
	//������
	CreateTree(BackArray,TreeDepth);
	//����
	pointTemp = MaxMinSearch(TreeDepth);
	//
	DeleteTree();
	return pointTemp;
}