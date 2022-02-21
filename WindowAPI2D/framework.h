// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//내가 추가한거
#include "CSingleTon.h"
#include "CCore.h"
#include "CTimeManager.h"
#include "struct.h"
#include "CGameObject.h"
#include "CKeyManager.h"
//STL
#include <vector>
#include <list>

//#디파인문# 매크로

#define WINSTYLE	 WS_CAPTION| WS_SYSMENU | WS_MINIMIZEBOX
#define WINSTARTX	100
#define WINSTARTY	100
#define WINSIZEX	1280	
#define WINSIZEY	720

#define DT CTimeManager::getInst()->GetDT();	


#define KEY(key)		CKeyManager::getInst()->GetButton(key)		//버튼이 눌림
#define KEYUP(key)		CKeyManager::getInst()->GetButtonUP(key)	//업키
#define KEYDOWN(key)	CKeyManager::getInst()->GetButtonDOWN(key)	//다운키

//========================================
//## 전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

