#pragma once

class CTimeManager
{
	SINGLETON(CTimeManager);


private:
	unsigned int m_uiFPS;
	double m_dDT;

public:
	void update(); // 한 업데이트당 fps,dt
	void init();   // 타임 매니저 초기화


	unsigned int GetFPS() { return m_uiFPS; }
	double GetDT() {return m_dDT;}
};