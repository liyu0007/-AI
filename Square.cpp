#include "Square.h"


CSquare::CSquare(void)
{
	Black = NULL;
	White = NULL;
	point.x = -50;
	point.y = -50;
}


CSquare::~CSquare(void)
{
	DeleteObject(Black);
	DeleteObject(White);
	Black = NULL;
	White = NULL;
}
void CSquare::InitSquare(HINSTANCE hIns)
{
	Black = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKSQURE));
	White = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITESQURE));
}
void CSquare::Show(HDC hdc)
{
	HDC hdcWhite = CreateCompatibleDC(hdc);
	HDC hdcBlack = CreateCompatibleDC(hdc);
	SelectObject(hdcBlack,Black);
	SelectObject(hdcWhite,White);
	BitBlt(hdc,point.x*33-18+19,point.y*33-18+94,36,36,hdcBlack,0,0,SRCPAINT);
	BitBlt(hdc,point.x*33-18+19,point.y*33-18+94,36,36,hdcWhite,0,0,SRCAND);
	DeleteDC(hdcWhite);
	DeleteDC(hdcBlack);
}