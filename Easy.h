#pragma once
#ifndef _CEASY_
#define _CEASY_
#include "artificialintelligence.h"
class CEasy :
	public CArtificialIntelligence
{
public:
	
public:
	CEasy(void);
	~CEasy(void);
public:
	virtual POINT CreateChess(CBackArray BackArray);
};
#endif