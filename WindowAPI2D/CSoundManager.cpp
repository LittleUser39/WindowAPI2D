#include "framework.h"
#include "CSoundManager.h"
#include "CSound.h"

CSoundManager::CSoundManager()
{
	m_pSystem = nullptr;
}

CSoundManager::~CSoundManager()
{
	m_pSystem->release();
	m_pSystem->close();
}

System* CSoundManager::GetSystem()
{
	return m_pSystem;
}

void CSoundManager::init()
{
	FMOD_RESULT result;
	result = System_Create(&m_pSystem);
	assert(!result);
	result = m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	assert(!result);
	
}

void CSoundManager::Update()
{
	m_pSystem->update();
}

void CSoundManager::AddSound(wstring keyName, wstring fillPath, bool bgm)
{
	CSound* pSound=CResourceManager::getInst()->LoadSound(keyName,fillPath);
	pSound->SetLoop(bgm);
	m_mapSound.insert(make_pair(keyName, pSound));
	
}

void CSoundManager::Play(wstring KeyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(KeyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Play();
}

void CSoundManager::Stop(wstring KeyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(KeyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Stop();
}

void CSoundManager::Pause(wstring KeyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(KeyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Pause();
}

void CSoundManager::Resume(wstring KeyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(KeyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Resume();
}

bool CSoundManager::IsPlaySound(wstring KeyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(KeyName);
	if (iter == m_mapSound.end())
		assert(nullptr);
	iter->second->IsPlay();

	return false;
}

bool CSoundManager::IsPauseSound(wstring KeyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(KeyName);
	if (iter == m_mapSound.end())
		assert(nullptr);
	iter->second->IsPlay();

	return false;
}
