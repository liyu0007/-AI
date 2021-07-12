#include "BACK.h"


CBACK::CBACK(void)
{
	ChessBoard = NULL;
	point.x = 0;
	point.y = 0;
}


CBACK::~CBACK(void)
{
	::DeleteObject(ChessBoard);
	ChessBoard = NULL;
}
void CBACK::InitBack(HINSTANCE hIns)
{
	ChessBoard = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKGROUND));
}
void CBACK::Show(HDC hdc)
{
	HDC hdcTemp = CreateCompatibleDC(hdc);
	SelectObject(hdcTemp,ChessBoard);
	BitBlt(hdc,0,0,500,575,hdcTemp,0,0,SRCCOPY);
	DeleteDC(hdcTemp);
}
