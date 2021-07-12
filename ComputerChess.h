#pragma once
#ifndef _CCOMPUTERCHESS_
#define _CCOMPUTERCHESS_
#include"sys.h"
class CComputerChess
{
public:
	HBITMAP ComputerWhite;
	HBITMAP ComputerBlack;
	POINT point;
public:
	CComputerChess(void);
	~CComputerChess(void);
public:
	void InitComputerChess(HINSTANCE hIns);
	void Show(HDC hdc);
};

#endif