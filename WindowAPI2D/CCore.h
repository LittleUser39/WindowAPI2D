#pragma once


class CCore
{
	SINGLETON(CCore);

	CCore();
	~CCore();

private:
	HDC m_hDC;

public:
	void update();
	void render();
	void init();
};