#pragma once
#include "artificialintelligence.h"
class CHard :
	public CArtificialIntelligence
{
public:
	CHard(void);
	~CHard(void);
public:
	virtual POINT CreateChess(CBackArray BackArray);

};

