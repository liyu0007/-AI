#pragma once
#ifndef _CGAMECTRL_
#define _CGAMECTRL_
#include"sys.h"
class CGameCtrl;
typedef CGameCtrl* (*pFun_Create_object)();//��������ĺ���ָ��
//ͨ���������ָ��������������һ������Ķ������Ҫ������и�ֵ
//���������ⲻ��ִ�и�ֵ��������ȷ�����������£���ͬ����Ҫ��ֵҲ��ͬ
//����ÿ�ξͶ�Ҫ�޸�������������ݡ�����Ҫ������������ݱ��ֲ��䣬����ʲô����
//�������޸ģ�����ԭ��ֻ�����ĵ�ԭ�򣩣�����õ��˶�̬��������

//���
//��������ĺ�������
#define DECLARE() static CGameCtrl* CreateObject();
//����ʵ��
#define IMPLEMENT(ThisClass) \
	CGameCtrl* ThisClass::CreateObject()\
	{\
         return new ThisClass; \
	}\
	Init Init##ThisClass(&ThisClass::CreateObject);

class CGameCtrl
{
public:
	static pFun_Create_object pFunCreateObject;//�����ʼ��
protected:
	HWND m_hwnd;
	HINSTANCE m_hIns;
public:
	CGameCtrl(void)
	{
		m_hwnd = NULL;
		m_hIns = NULL;
	}
	void SetHandle(HWND hwnd,HINSTANCE hIns)
	{
		m_hwnd = hwnd;
		m_hIns = hIns;
	}
	virtual ~CGameCtrl(void)
	{

	}
public:
	virtual void OnCreateGame(){}       //WM_CREATE
	virtual void OnDrawGame(){}			//WM_PAINT
	virtual void OnRunGame(WPARAM TimerID){}			//WM_TIMER
	virtual void OnLBottonDown(POINT){}		//WM_LBOTTONDOWN
	virtual void MouseMove(POINT){} 
	virtual void OnLBottonUp(){}
	/****************************************/
	virtual void UndoOnce(){}//����
	virtual void SetPlayerFirst(){}//��������
	virtual void SetComputerFirst(){}
	virtual void GiveUp(){}//����
	//�Ѷ�����
	virtual void SetEasy(){}
	virtual void SetNormal(){}
	virtual void SetHard(){}
};

class Init
{
public:
	Init(pFun_Create_object pFun)
	{
		CGameCtrl::pFunCreateObject = pFun;
	}
};
#endif
