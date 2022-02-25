// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once
#pragma comment(lib, "Msimg32.lib")

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
//STL
#include <vector>
#include <list>
#include <string>
#include <math.h>
#include <map>
#include <assert.h>
#include "Logger.h"
#define PHI 3.141592
using namespace std;

//========================================
//## 오브젝트 그룹						##
//========================================
//열거형 클래스
//아니 이것도 저 해더들보다 위에 있어야함
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,

	SIZE,
};
enum class GROUP_SCENE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	SIZE,
};
//내가 추가한거
#include "CSingleTon.h"
#include "struct.h"
#include "CCore.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CResourceManager.h"


//========================================
//## 디파인 매크로						##
//========================================
#define WINSTYLE	 WS_CAPTION| WS_SYSMENU | WS_MINIMIZEBOX
#define WINSTARTX	100
#define WINSTARTY	100
#define WINSIZEX	1280	
#define WINSIZEY	720

#define DT				CTimeManager::getInst()->GetDT();	
#define fDT				CTimeManager::getInst()->GetfDT()


#define KEY(key)		CKeyManager::getInst()->GetButton(key)		//버튼이 눌림
#define KEYUP(key)		CKeyManager::getInst()->GetButtonUp(key)	//업키
#define KEYDOWN(key)	CKeyManager::getInst()->GetButtonDown(key)	//다운키

//========================================
//## 전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

