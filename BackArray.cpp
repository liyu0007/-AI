#include "BackArray.h"


CBackArray::CBackArray(void)
{
	for(int i = 0;i < 15;i++)
	{
		for(int j = 0;j < 15;j++)
		{
			ChessBoard[i][j] = 0;
		}
	}
}

CBackArray::~CBackArray(void)
{

}

void CBackArray::InitBackArray()
{
	for(int i = 0;i < 15;i++)
	{
		for(int j = 0;j < 15;j++)
		{
			ChessBoard[i][j] = 0;
		}
	}
}

void CBackArray::UpdataChessBoard(list<CPlayerChess*> PlayerList)
{
	list<CPlayerChess*>::iterator ite = PlayerList.begin();
	while(ite != PlayerList.end())
	{
		ChessBoard[(*ite)->point.y][(*ite)->point.x] = 1;
		ite++;
	}
}