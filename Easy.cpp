#include "Easy.h"
CEasy::CEasy(void):CArtificialIntelligence(1)
{
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			Score[i][j] = 0;
		}
	}
}


CEasy::~CEasy(void)
{

}

POINT CEasy::CreateChess(CBackArray BackArray)
{
	POINT pointTemp;
	this->GetScore(BackArray,0,Score);
	pointTemp = FindMax(Score);
	this->InitScore(Score);
	return pointTemp;
}