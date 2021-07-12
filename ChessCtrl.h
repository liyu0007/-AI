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
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
class CChessCtrl :
	public CGameCtrl
{
public:
	DECLARE()
public:
	int playerORcomuter;//1 �����£�0 �����£���ֵ-1
	int gamestart;//��1Ϊ��Ϸ��ʼ����Ϸһ����ʼ�������ٸ���playerORcomuter
	//���ǿ����л� ��Ϸ�Ѷȵȼ�
	//��Ϸһ��ʼ�Ѷ�Ĭ���ǳ���,��������;�޸�
	int CountPlayer;//���Ӹ���
	int CountComputer;
public:
	CArtificialIntelligence* CAI;
	CBackArray BackArray;
	CBACK BackGround;//�������Ӻ�ɾ��ʱ��˳����£����ص��ú�����
	CSquare Square;//Ԥ���
	list<CPlayerChess*> PlayerList;//��������
	list<CComputerChess*> ComputerList;//��������
public:
	CChessCtrl(void);
	~CChessCtrl(void);
public:
	virtual void OnCreateGame();       //WM_CREATE
	virtual void OnDrawGame();			//WM_PAINT
	virtual void OnRunGame(WPARAM TimerID);			//WM_TIMER
	virtual void OnLBottonDown(POINT);		//WM_LBOTTONDOWN�����ֶ�����
	//virtual void OnLBottonUp();   //�����Զ����壬
	//�������¸ĵ���ʱ����
	virtual void MouseMove(POINT);
	virtual void UndoOnce();//���壬����һ������һ���������壬
	//Ҳ����˵������ֵ���������,
	virtual void SetPlayerFirst();//��������
	virtual void SetComputerFirst();//���õ�������һ��������Ԫ
	virtual void GiveUp();//���䣬��������Ϸ��Ҫ��ʼ�����б�����ɾ��֮ǰ����������
	virtual void SetEasy();
	virtual void SetNormal();
	virtual void SetHard();
	/*********************/
	POINT GetNearest(POINT point);//��ȡ�뵱ǰ������������,ʵ�ʾ��Ƕ�ά�����±�
	void CreatePlayerChess(POINT point);//���������µ���
	void CreateComputerChess(POINT point);//���������µ���
	void ComputerPlayChess();//��������

	void ShowPlayerChess(HDC hdc);
	void ShowComputerChess(HDC hdc);

	bool IsTieGame();//�������Ӹ������ɣ�����һ��225����
	//��������Ŀ������Ϊ�ڱ�������õ��������
	bool PlayerWinGame(CBackArray BackArray);//1��ʾ��Ӯ�� 0��ʾ�����Ӯ
	bool ComputerWinGame(CBackArray BackArray);

	void DeleteAllChess();
	static int Round_Off(double a);//�������뺯��
};

#endif