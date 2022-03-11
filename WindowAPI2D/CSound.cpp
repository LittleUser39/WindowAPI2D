#include "framework.h"
#include "CSound.h"

CSound::CSound()
{
	m_pSound	=	nullptr;
	m_pChannel	=	nullptr;
	
}

CSound::~CSound()
{
	Stop();
	if (nullptr != m_pSound)
	{
		m_pSound->release();
	}
}

void CSound::Play()
{
	CSoundManager::getInst()->GetSystem()->playSound(m_pSound, nullptr, false, &m_pChannel);
	assert(m_pChannel);
}

void CSound::Stop()
{
	if (nullptr != m_pChannel)
		m_pChannel->stop();
}

void CSound::Pause()
{
	if (nullptr != m_pChannel)
		m_pChannel->setPaused(true);

}

void CSound::Resume()
{
	if (nullptr != m_pChannel)
		m_pChannel->setPaused(true);
}

bool CSound::IsPlay()
{
	bool playing = false;
	if (nullptr != m_pChannel)
		m_pChannel->isPlaying(&playing);

	return playing;
}

bool CSound::IsPause()
{
	bool paused = false;
	if (nullptr != m_pChannel)
		m_pChannel->getPaused(&paused);

	return paused;
}

void CSound::SetLoop(bool loop)
{
	if(loop)
		m_pSound->setMode(FMOD_DEFAULT);
	else
		m_pSound->setMode(FMOD_LOOP_OFF);
}

void CSound::Load(const wstring& strFillPath)
{
	char str[255];
	wcstombs_s(nullptr, str, strFillPath.c_str(), 255);

	CSoundManager::getInst()->GetSystem()->createSound(str, FMOD_DEFAULT, nullptr, &m_pSound);
}
