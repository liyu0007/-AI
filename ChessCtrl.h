#pragma once
#ifndef _CHESSCTRL_
#define _CHESSCTRL_
#include"ComputerChess.h"
#include"PlayerChess.h"
#include "GameCtrl.h"
#include"BACK.h"
#include"Square.h"
#include"BackArray.h"
#include"Easy.h"
#include"Normal.h"
#include"Hard.h"
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库
class CChessCtrl :
	public CGameCtrl
{
public:
	DECLARE()
public:
	int playerORcomuter;//1 棋手下，0 电脑下，初值-1
	int gamestart;//置1为游戏开始，游戏一旦开始，不能再更改playerORcomuter
	//但是可以切换 游戏难度等级
	//游戏一开始难度默认是初级,可以在中途修改
	int CountPlayer;//棋子个数
	int CountComputer;
public:
	CArtificialIntelligence* CAI;
	CBackArray BackArray;
	CBACK BackGround;//创建棋子和删除时候顺便更新，不必调用函数了
	CSquare Square;//预瞄点
	list<CPlayerChess*> PlayerList;//棋手棋子
	list<CComputerChess*> ComputerList;//电脑棋子
public:
	CChessCtrl(void);
	~CChessCtrl(void);
public:
	virtual void OnCreateGame();       //WM_CREATE
	virtual void OnDrawGame();			//WM_PAINT
	virtual void OnRunGame(WPARAM TimerID);			//WM_TIMER
	virtual void OnLBottonDown(POINT);		//WM_LBOTTONDOWN，人手动下棋
	//virtual void OnLBottonUp();   //电脑自动下棋，
	//将电脑下改到定时器中
	virtual void MouseMove(POINT);
	virtual void UndoOnce();//悔棋，悔棋一次至上一次棋手下棋，
	//也就是说悔棋后，轮到棋手下棋,
	virtual void SetPlayerFirst();//设置先手
	virtual void SetComputerFirst();//设置电脑先手一定下在天元
	virtual void GiveUp();//认输，即重新游戏，要初始化所有变量，删除之前的所有棋子
	virtual void SetEasy();
	virtual void SetNormal();
	virtual void SetHard();
	/*********************/
	POINT GetNearest(POINT point);//获取离当前点最近的下棋点,实际就是二维数组下标
	void CreatePlayerChess(POINT point);//创建棋手下的棋
	void CreateComputerChess(POINT point);//创建电脑下的棋
	void ComputerPlayChess();//电脑下棋

	void ShowPlayerChess(HDC hdc);
	void ShowComputerChess(HDC hdc);

	bool IsTieGame();//根据棋子个数即可，棋盘一共225颗子
	//传参数的目的是因为在别的类里用到这个函数
	bool PlayerWinGame(CBackArray BackArray);//1表示人赢了 0表示计算机赢
	bool ComputerWinGame(CBackArray BackArray);

	void DeleteAllChess();
	static int Round_Off(double a);//四舍五入函数
};

#endif