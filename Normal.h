#pragma once
#include "artificialintelligence.h"
class CNormal :
	public CArtificialIntelligence
{
public:
	CNormal(void);
	~CNormal(void);
public:
	virtual POINT CreateChess(CBackArray BackArray);

};

