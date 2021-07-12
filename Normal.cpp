#include "Normal.h"


CNormal::CNormal(void):CArtificialIntelligence(6)
{
	TreeDepth = 6;
}


CNormal::~CNormal(void)
{

}

POINT CNormal::CreateChess(CBackArray BackArray)
{
	POINT pointTemp = {0};
	//´´½¨Ê÷
	CreateTree(BackArray,TreeDepth);
	//ËÑË÷
	pointTemp = MaxMinSearch(TreeDepth);
	//
	DeleteTree();
	return pointTemp;
}