#pragma once

class CTimeManager
{
	SINGLETON(CTimeManager);


private:
	unsigned int m_uiFPS;
	double m_dDT;

public:
	void update(); // �� ������Ʈ�� fps,dt
	void init();   // Ÿ�� �Ŵ��� �ʱ�ȭ


	unsigned int GetFPS() { return m_uiFPS; }
	double GetDT() {return m_dDT;}
};