#include "ComputerChess.h"


CComputerChess::CComputerChess(void)
{
	ComputerBlack = NULL;
	ComputerWhite = NULL;
	point.x = -50;
	point.y = -50;
}


CComputerChess::~CComputerChess(void)
{
	DeleteObject(ComputerBlack);
	DeleteObject(ComputerWhite);
	ComputerBlack = NULL;
	ComputerWhite = NULL;
}

void CComputerChess::InitComputerChess(HINSTANCE hIns)
{
	ComputerBlack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKCHESSBLACKBACK));
	ComputerWhite = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BLACKCHESSWHITEBACK));
}
void CComputerChess::Show(HDC hdc)
{
	HDC hdcTempWhite = CreateCompatibleDC(hdc);
	SelectObject(hdcTempWhite,ComputerWhite);
	BitBlt(hdc,point.x*33-15+19,point.y*33-15+94,34,34,hdcTempWhite,0,0,SRCAND);
	DeleteDC(hdcTempWhite);

	HDC hdcTempBlack = CreateCompatibleDC(hdc);
	SelectObject(hdcTempBlack,ComputerBlack);
	BitBlt(hdc,point.x*33-15+19,point.y*33-15+94,34,34,hdcTempBlack,0,0,SRCPAINT);
	DeleteDC(hdcTempBlack);
}