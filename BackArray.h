#pragma once
#ifndef _CBACKARRAY_
#define _CBACKARRAY_
#include"sys.h"
#include"PlayerChess.h"
class CBackArray
{
public:
	int ChessBoard[15][15];//���̣�0��ʾû���ӣ�1�����ְ�����ӣ�2��ʾ���Ժ������
	//��������������˶���1��ʾ�������ӣ�2��ʾ��������
public:
	CBackArray(void);
	~CBackArray(void);
public:
	void InitBackArray();
	void UpdataChessBoard(list<CPlayerChess*> PlayerList);//������ChessCtrl�У���û����
	//
};

#endif