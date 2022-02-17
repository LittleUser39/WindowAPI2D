#pragma once
#include "CSingleTon.h"

class CCore
{
	SINGLETON(CCore);

public:
	void update();
	void render();
};