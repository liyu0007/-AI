#pragma once
#ifndef _SQUARE_
#define _SQUARE_
#include"sys.h"
class CSquare
{
public:
	HBITMAP Black;
	HBITMAP White;
	POINT point;
public:
	CSquare(void);
	~CSquare(void);
public:
	void InitSquare(HINSTANCE hIns);
	void Show(HDC hdc);
};

#endif