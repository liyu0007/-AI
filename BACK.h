#pragma once
#ifndef _BCAKGROUND_
#define _BCAKGROUND_
#include"sys.h"
class CBACK
{
public:
	HBITMAP ChessBoard;
	POINT point;
public:
	CBACK(void);
	~CBACK(void);
public:
	void InitBack(HINSTANCE hIns);
	void Show(HDC hdc);
};
#endif
