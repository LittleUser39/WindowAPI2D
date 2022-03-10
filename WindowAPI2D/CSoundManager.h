#pragma once
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib, "FMOD/lib/fmod_vc.lib")

using namespace FMOD;

class CSound;

class CSoundManager
{
	SINGLETON(CSoundManager);

private:
	map<wstring, CSound*> m_mapSound;
	
	System* m_pSystem;

public:
	System* GetSystem();

	void init();
	void Update();

	void AddSound(wstring keyName, wstring fillPath, bool bgm);
	void Play(wstring KeyName);
	void Stop(wstring KeyName);
	void Pause(wstring KeyName);
	void Resume(wstring KeyName);

	bool IsPlaySound(wstring KeyName);
	bool IsPauseSound(wstring KeyName);
};

