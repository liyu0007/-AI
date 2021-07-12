#pragma once
#ifndef _CGAMECTRL_
#define _CGAMECTRL_
#include"sys.h"
class CGameCtrl;
typedef CGameCtrl* (*pFun_Create_object)();//创建对象的函数指针
//通过这个函数指针在主函数创建一个子类的对象，因此要对其进行赋值
//在主函数外不能执行赋值操作，不确定子类的情况下，不同子类要赋值也不同
//这样每次就都要修改主函数里的内容。现在要求这个壳子内容保持不变，无论什么子类
//都不用修改（开闭原则，只增不改的原则），因此用到了动态创建对象

//封宏
//创建对象的函数声明
#define DECLARE() static CGameCtrl* CreateObject();
//函数实现
#define IMPLEMENT(ThisClass) \
	CGameCtrl* ThisClass::CreateObject()\
	{\
         return new ThisClass; \
	}\
	Init Init##ThisClass(&ThisClass::CreateObject);

class CGameCtrl
{
public:
	static pFun_Create_object pFunCreateObject;//类外初始化
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
	virtual void UndoOnce(){}//悔棋
	virtual void SetPlayerFirst(){}//设置先手
	virtual void SetComputerFirst(){}
	virtual void GiveUp(){}//认输
	//难度设置
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
