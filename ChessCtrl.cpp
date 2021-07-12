#include "ChessCtrl.h"

IMPLEMENT(CChessCtrl)
CChessCtrl::CChessCtrl(void)
{
	playerORcomuter = -1;
	gamestart = 0;
	CountPlayer = 0;
	CountComputer = 0;
	CAI = new CEasy;
}


CChessCtrl::~CChessCtrl(void)
{
	DeleteAllChess();
}
void CChessCtrl::DeleteAllChess()
{
	//删除棋手的棋子
	list<CPlayerChess*>::iterator itePlayer = PlayerList.begin();
	while(itePlayer != PlayerList.end())
	{
		delete (*itePlayer);//先删除指针指向的对象
		itePlayer = PlayerList.erase(itePlayer);//再删除这个结点
	}
	//删除电脑棋子
	list<CComputerChess*>::iterator iteComputer = ComputerList.begin();
	while(iteComputer != ComputerList.end())
	{
		delete (*iteComputer);//
		iteComputer = ComputerList.erase(iteComputer);
	}
}

void CChessCtrl::OnCreateGame()       //WM_CREATE
{
	BackArray.InitBackArray();
	BackGround.InitBack(m_hIns);
	Square.InitSquare(m_hIns);
	SetTimer(m_hwnd,TIMERIDDRAWAGAIN,100,NULL);
	SetTimer(m_hwnd,COPMPUTERPLAYCHESS,200,NULL);
}
void CChessCtrl::OnDrawGame()			//WM_PAINT
{
	HDC hdc = GetDC(m_hwnd);//窗口DC
	HDC hdcTemp = CreateCompatibleDC(hdc);//兼容DC
	HBITMAP bitmapTemp = CreateCompatibleBitmap(hdc,500,575);//兼容性位图
	//在这个兼容性DC上画完，再传入窗口DC，解决闪屏问题
	::SelectObject(hdcTemp,bitmapTemp);
	//显示背景
	BackGround.Show(hdcTemp);
	if(playerORcomuter == 1)
	{
		Square.Show(hdcTemp);
	}
	ShowPlayerChess(hdcTemp);
	ShowComputerChess(hdcTemp);

	::BitBlt(hdc,0,0,500,575,hdcTemp,0,0,SRCCOPY);
	::DeleteObject(bitmapTemp);
	::DeleteDC(hdcTemp);
	::ReleaseDC(m_hwnd,hdc);
}
void CChessCtrl::OnRunGame(WPARAM TimerID)		//WM_TIMER
{
	if(TimerID == TIMERIDDRAWAGAIN)
	{
	//电脑下棋
		
		this->OnDrawGame();
	}
	if(COPMPUTERPLAYCHESS == TimerID)
	{
		this->ComputerPlayChess();
	}
}
void CChessCtrl::OnLBottonDown(POINT point)		//WM_LBOTTONDOWN
{
	int temp = CountPlayer;
	if(playerORcomuter == 1)
	{
		if(point.x >=0 && point.x <= 500 && point.y >= 76 && point.y <= 575)
		{
			POINT pointTemp = GetNearest(point);
			if(BackArray.ChessBoard[pointTemp.y][pointTemp.x] == 0)//空位置
			{
				CreatePlayerChess(pointTemp);
				CountPlayer++;
				playerORcomuter = 0;
				
				//创建一个棋子。判断胜负
				if( PlayerWinGame(BackArray) )
				{
					playerORcomuter = -1;
					this->OnDrawGame();
					//PlaySound(MAKEINTRESOURCE(IDR_WAVE3),GetModuleHandle(NULL), SND_RESOURCE);
					MessageBox(m_hwnd,L"NB，你赢啦！",L"提示",MB_OK);
					return;
				}
				//判断和棋
				if(this->IsTieGame())
				{
					playerORcomuter = -1;
					MessageBox(m_hwnd,L"猪，和棋啦！",L"提示",MB_OK);
					return;
				}

			}
		}
	}
	else
	{
		if(point.y >= 94-17)
			MessageBox(m_hwnd,L"请先从游戏菜单中选择先手方",L"提示",MB_OK);
	}
	this->OnDrawGame();
	if(temp != CountPlayer)
		PlaySound(MAKEINTRESOURCE(IDR_WAVE2),GetModuleHandle(NULL), SND_RESOURCE);
}


void CChessCtrl::UndoOnce()//悔棋
{
	if(!PlayerWinGame(BackArray))
	{
		//先删除一个黑子
		if(CountComputer != 0)//有黑子
		{
			//先得到最后一个棋子的坐标,把背景数组变回去
			list<CComputerChess*>::iterator iteComputer = --ComputerList.end();
			POINT pointTemp = (*iteComputer)->point;
			BackArray.ChessBoard[pointTemp.y][pointTemp.x] = 0;
			//删除黑子
			delete (*iteComputer);
			ComputerList.pop_back();
			//黑子个数剪1
			CountComputer--;
			playerORcomuter = 0;
			//再删除白子
			if(CountPlayer != 0)//有白子
			{
				list<CPlayerChess*>::iterator itePlayer = --PlayerList.end();
				pointTemp = (*itePlayer)->point;
				BackArray.ChessBoard[pointTemp.y][pointTemp.x] = 0;
				delete (*itePlayer);
				PlayerList.pop_back();
				CountPlayer--;
				playerORcomuter = 1;
			}
		}
	}
	else
	{
		if(CountPlayer != 0)//有白子
			{
				list<CPlayerChess*>::iterator itePlayer = --PlayerList.end();
				POINT pointTemp = (*itePlayer)->point;
				BackArray.ChessBoard[pointTemp.y][pointTemp.x] = 0;
				delete (*itePlayer);
				PlayerList.pop_back();
				CountPlayer--;
				playerORcomuter = 1;
			}
	}
}

void CChessCtrl::SetPlayerFirst()//设置先手
{
	if(gamestart == 0)
	{
		playerORcomuter = 1;
		gamestart = 1;
	}
	else
	{
		MessageBox(m_hwnd,L"游戏已开始，无法调整先后手",L"提示",MB_OK);
	}
}

void CChessCtrl::SetComputerFirst()
{
	if(gamestart == 0)
	{
		playerORcomuter = 0;
		gamestart = 1;
	}
	else
	{
		MessageBox(m_hwnd,L"游戏已开始，无法调整先后手",L"提示",MB_OK);
	}
}

void CChessCtrl::SetEasy()
{
	if(CAI != NULL)
	{
		delete CAI;
		CAI = NULL;
		CAI = new CEasy;
	}
	else
	{
		CAI = new CEasy;
	}
}
void CChessCtrl::SetNormal()
{
	if(CAI != NULL)
	{
		delete CAI;
		CAI = NULL;
		CAI = new CNormal;
	}
	else
	{
		CAI = new CNormal;
	}
}
void CChessCtrl::SetHard()
{
	if(CAI != NULL)
	{
		delete CAI;
		CAI = NULL;
		CAI = new CHard;
	}
	else
	{
		CAI = new CHard;
	}
}

void CChessCtrl::GiveUp()
{
	if(gamestart == 1)
	{
		//先删除
		DeleteAllChess();
		playerORcomuter = -1;
		gamestart = 0;
		CountPlayer = 0;
		CountComputer = 0;
		BackArray.InitBackArray();
	}
}
//**************************************************//
void CChessCtrl::ComputerPlayChess()
{
	int tempCount = CountComputer;
	if(playerORcomuter == 0)//轮到电脑下
	{
		POINT pointTemp;
		//先获取下棋的坐标，
		if(CountComputer+CountPlayer == 0)
		{
			pointTemp.x = 7;
			pointTemp.y = 7;
		}
		//**这部分未实现(核心算法部分)**********************************************
		else
		{
			pointTemp = CAI->CreateChess(BackArray);
		}
		//*************************************************************
		
		//创建电脑下的棋
		if(BackArray.ChessBoard[pointTemp.y][pointTemp.x] == 0)//没有棋子
		{
			CreateComputerChess(pointTemp);
			Square.point = pointTemp;
			CountComputer++;
			playerORcomuter = 1;
			
			if( ComputerWinGame(BackArray) )
			{
				playerORcomuter = -1;
				this->OnDrawGame();
				MessageBox(m_hwnd,L"你是猪么，这都能输！",L"提示",MB_OK);
				return;
			}
			if(this->IsTieGame())
			{
				MessageBox(m_hwnd,L"猪，和棋啦！",L"提示",MB_OK);
				playerORcomuter = -1;
				return;
			}
		}
		else//否则表示最高得分是0，就算和棋
		{
			playerORcomuter = -1;
			MessageBox(m_hwnd,L"哎！这局只能算和棋了！",L"提示",MB_OK);
			return;
		}
	}
	this->OnDrawGame();
	if(tempCount != CountComputer)
		PlaySound(MAKEINTRESOURCE(IDR_WAVE2),GetModuleHandle(NULL), SND_RESOURCE);
}
void CChessCtrl::MouseMove(POINT point)
{
	if(point.x >=0 && point.x <= 500 && point.y >= 76 && point.y <= 575)
	{
		Square.point = GetNearest(point);
	}
	else
	{
		Square.point.x = Square.point.y = -50;
	}
	this->OnDrawGame();
}
void CChessCtrl::CreateComputerChess(POINT point)
{
	CComputerChess* temp = new CComputerChess;
	temp->InitComputerChess(m_hIns);
	temp->point = point;
	ComputerList.push_back(temp);

	BackArray.ChessBoard[point.y][point.x] = 2;
}
void CChessCtrl::CreatePlayerChess(POINT point)
{
	CPlayerChess* temp = new CPlayerChess;
	temp->InitPlayer(m_hIns);
	temp->point = point;
	PlayerList.push_back(temp);
	//创建一个棋子，要更新一下BackArray
	BackArray.ChessBoard[point.y][point.x] = 1;
}
POINT CChessCtrl::GetNearest(POINT point)
{
	double x = (double)((point.x)-19)/33;
	double y = (double)((point.y)-94)/33;
	POINT pointemp;
	pointemp.x = Round_Off(x);
	pointemp.y = Round_Off(y);
	if(pointemp.x < 0)
	{
		pointemp.x = 0;
	}
	if(pointemp.y < 0)
	{
		pointemp.y = 0;
	}
	if(pointemp.x > 14)
	{
		pointemp.x = 14;
	}
	if(pointemp.y > 14)
	{
		pointemp.y = 14;
	}
	return pointemp;
}
int CChessCtrl::Round_Off(double a)
{
	if(a>0)
	{
		if((a-int(a))>=0.5)
		{
			return int(a+1);
		}
		else
		{
			return int(a);
		}
	}
	else if(a<0)
	{
		if(( (-a) - int(-a) ) > 0.5)
		{
			return -((int)(-a+1));
		}
		else
		{
			return -((int)(-a));
		}
	}
	else
	{
		return 0;
	}
}
void CChessCtrl::ShowPlayerChess(HDC hdc)
{
	list<CPlayerChess*>::iterator ite = PlayerList.begin();
	while(ite != PlayerList.end())
	{
		(*ite)->Show(hdc);
		ite++;
	}
}
void CChessCtrl::ShowComputerChess(HDC hdc)
{
	list<CComputerChess*>::iterator ite = ComputerList.begin();
	while(ite != ComputerList.end())
	{
		(*ite)->Show(hdc);
		ite++;
	}
}

bool CChessCtrl::IsTieGame()//根据棋子个数即可，棋盘一共225颗子
{
	if( (CountPlayer + CountComputer) == 225)
		return 1;
	return 0;
}
bool CChessCtrl::PlayerWinGame(CBackArray BackArray)//1表示人赢了 0表示计算机赢
{
	//横排五元组
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i][j+1] == 1
				&& BackArray.ChessBoard[i][j+2] == 1 && BackArray.ChessBoard[i][j+3] == 1
				&&  BackArray.ChessBoard[i][j+4] == 1)
				
				return 1;
		}
	}
	//竖排五元组
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i+1][j] == 1
				&& BackArray.ChessBoard[i+2][j] == 1 && BackArray.ChessBoard[i+3][j] == 1
				&&  BackArray.ChessBoard[i+4][j] == 1)
				return 1;
		}
	}
	//左斜着的五元组
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i+1][j+1] == 1
				&& BackArray.ChessBoard[i+2][j+2] == 1 && BackArray.ChessBoard[i+3][j+3] == 1
				&&  BackArray.ChessBoard[i+4][j+4] == 1)
				return 1;
		}
	}
	//右斜着的五元组
	for(int i = 4;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i-1][j+1] == 1
				&& BackArray.ChessBoard[i-2][j+2] == 1 && BackArray.ChessBoard[i-3][j+3] == 1
				&&  BackArray.ChessBoard[i-4][j+4] == 1)
				return 1;
		}
	}
	return 0;
}

bool CChessCtrl::ComputerWinGame(CBackArray BackArray)//1表示人赢了 0表示计算机赢
{
	//横排五元组
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i][j+1] == 2
				&& BackArray.ChessBoard[i][j+2] == 2 && BackArray.ChessBoard[i][j+3] == 2
				&&  BackArray.ChessBoard[i][j+4] == 2)
				return 1;
		}
	}
	//竖排五元组
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i+1][j] == 2
				&& BackArray.ChessBoard[i+2][j] == 2 && BackArray.ChessBoard[i+3][j] == 2
				&&  BackArray.ChessBoard[i+4][j] == 2)
				return 1;
		}
	}
	//左斜着的五元组
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i+1][j+1] == 2
				&& BackArray.ChessBoard[i+2][j+2] == 2 && BackArray.ChessBoard[i+3][j+3] == 2
				&&  BackArray.ChessBoard[i+4][j+4] == 2)
				return 1;
		}
	}
	//右斜着的五元组
	for(int i = 4;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i-1][j+1] == 2
				&& BackArray.ChessBoard[i-2][j+2] == 2 && BackArray.ChessBoard[i-3][j+3] == 2
				&&  BackArray.ChessBoard[i-4][j+4] == 2)
				return 1;
		}
	}
	return 0;
}