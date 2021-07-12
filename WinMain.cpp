#include"sys.h"
#include"ChessCtrl.h"
pFun_Create_object CGameCtrl::pFunCreateObject = NULL;//类外初始化
HINSTANCE hIns;
LRESULT CALLBACK MY_WNDPROC(HWND,UINT,WPARAM,LPARAM);
int CALLBACK WinMain(HINSTANCE hinstance,//当前实例句柄
					 HINSTANCE hPrevInstance, //前一个应用实例句柄
					 LPSTR lpCmdLine,//命令行参数
					int nCmdShow/*窗口显示类型*/)
{
	//****函数测试*****************************************
	srand((unsigned int)time(0));
	//*********************************************
	hIns = hinstance;
	int CX = ::GetSystemMetrics(SM_CXSCREEN );//得到屏幕分辨率
	int CY = ::GetSystemMetrics(SM_CYSCREEN );
	int Height = 575;
	int Width = 500;
	//设计窗口
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = CreateSolidBrush(RGB(255,255,255));
	wndclass.hCursor = ::LoadCursor(NULL,MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = ::LoadIcon(NULL,MAKEINTRESOURCE(IDI_ICON1));
	wndclass.hIconSm = 0;
	wndclass.hInstance = hinstance;
	wndclass.lpfnWndProc = MY_WNDPROC;
	wndclass.lpszClassName = L"郑忠慧";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;
	//注册
	if(!RegisterClassEx(&wndclass))
	{
		MessageBox(NULL,L"注册失败",L"提示",MB_OK);
		return 0; 
	}
	//创建
	HMENU menu = LoadMenu(hinstance,MAKEINTRESOURCE(IDR_MENU1));
	HWND hwnd = CreateWindow(L"郑忠慧",L"五子棋",WS_OVERLAPPEDWINDOW,(CX-Width)/2,(CY-Height)/2-40,
		Width+16,Height+38+20/*menu的高度*/,NULL,menu,hinstance,NULL);
	if(hwnd == NULL)
	{
		MessageBox(NULL,L"创建失败",L"提示",MB_OK);
		return 0;
	}
	//显示
	ShowWindow(hwnd,SW_SHOW);
	//消息循环
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
CGameCtrl* Ctrl = NULL;
LRESULT CALLBACK MY_WNDPROC(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
	switch(msg)
	{
	case WM_CREATE:
		if(CGameCtrl::pFunCreateObject == NULL)
		{
			MessageBox(NULL,L"创建对象失败",L"提示",MB_OK);
			DestroyWindow(hwnd);
			PostQuitMessage(0);
		}
		else
		{
			Ctrl = (*CGameCtrl::pFunCreateObject)();
			Ctrl->SetHandle(hwnd,hIns);
			Ctrl->OnCreateGame();
		}
		break;
	case WM_PAINT:
		Ctrl->OnDrawGame();
		break;
	case WM_TIMER:
		Ctrl->OnRunGame(wparam);
		break;
	case WM_LBUTTONDOWN:
		{
			POINT point;
			point.x = LOWORD(lparam);
			point.y = HIWORD(lparam);
			Ctrl->OnLBottonDown(point);
		}
		break;
	case WM_MOUSEMOVE:
		{
			//SetCapture(hwnd);//捕获鼠标，
			//窗口不在需要捕获的时候要释放
			POINT point;
			point.x = LOWORD(lparam);
			point.y = HIWORD(lparam);
			Ctrl->MouseMove(point);
			//ReleaseCapture();
		}
			break;
	case WM_COMMAND:
		switch(wparam)
		{
		case ID_PLAYERFIRST:
			Ctrl->SetPlayerFirst();
			break;
		case ID_COMPUTERFIRST:
			Ctrl->SetComputerFirst();
			break;
		case ID_EASY:
			Ctrl->SetEasy();
			break;
		case ID_NORMAL:
			Ctrl->SetNormal();
			break;
		case ID_HARD:
			Ctrl->SetHard();
			break;
		case ID_UNDO:
			Ctrl->UndoOnce();
			break;
		case ID_GIVEUP:
			Ctrl->GiveUp();	
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		delete Ctrl;
		Ctrl = NULL;
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd,msg,wparam,lparam);
}