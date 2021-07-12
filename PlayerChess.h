#pragma once
#ifndef _PLAYERCHESS_
#define _PLAYERCHESS_
#include"sys.h"
class CPlayerChess
{
public:
	HBITMAP PlayerWhite;
	HBITMAP PlayerBlack;
	POINT point;
public:
	CPlayerChess(void);
	~CPlayerChess(void);
public:
	void InitPlayer(HINSTANCE hIns);
	void Show(HDC);
};

#endif