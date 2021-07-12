#include "PlayerChess.h"


CPlayerChess::CPlayerChess(void)
{
	PlayerWhite = NULL;
	PlayerBlack = NULL;
	point.x = -50;
	point.y = -50;
}


CPlayerChess::~CPlayerChess(void)
{
	DeleteObject(PlayerWhite);
	PlayerWhite = NULL;
	DeleteObject(PlayerBlack);
	PlayerBlack = NULL;
}

void CPlayerChess::InitPlayer(HINSTANCE hIns)
{
	PlayerBlack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITECHESSBLACKBACK));
	PlayerWhite = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WHITECHESSWHITEBACK));
}
void CPlayerChess::Show(HDC hdc)
{
	HDC hdcTempWhite = CreateCompatibleDC(hdc);
	SelectObject(hdcTempWhite,PlayerWhite);
	BitBlt(hdc,point.x*33-15+19,point.y*33-15+94,34,34,hdcTempWhite,0,0,SRCAND);
	DeleteDC(hdcTempWhite);

	HDC hdcTempBlack = CreateCompatibleDC(hdc);
	SelectObject(hdcTempBlack,PlayerBlack);
	BitBlt(hdc,point.x*33-15+19,point.y*33-15+94,34,34,hdcTempBlack,0,0,SRCPAINT);
	DeleteDC(hdcTempBlack);
}