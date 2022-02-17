// WindowAPI2D.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowAPI2D.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;                                      // 현재 윈도우의 핸들값
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//_in_:SAL주석- 자주 사용되는 주석을 매번 적기보다 키워드로 작성함.
// hinstance : 실행된 프로세스의 시작주소, 인스턴스 핸들
//hPrevinstance : 이전에 실행된 인스턴스 핸들
//ipcmdLince : 명령으로 입력된 프로그램의 인수
//ncmdshow : 프로그램이 시작될 형태
//이게 윈도우 실행 메인 함수

//메인의 역할
//1. 윈도우창 세팅 후 화면에 띄움
//2. 메세지 루프
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //무시해도 되는 매개변수 들
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    
    // 전역 문자열을 초기화합니다.
    // 리소스에 있는 문자열을 불러오는 함수, 리소스 뷰의 string table에서 id값으로 string 가져오는함수
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWAPI2D, szWindowClass, MAX_LOADSTRING);
    //윈도우의 속성들을 정해주는 함수
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키 내용을 리소스에서 가져오는 함수
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWAPI2D));

   

    // 기본 메시지 루프입니다:
    //메세지 큐에서 메세지가 확인 될때까지 대기
    // 메세지 큐에 msg.message == WM_Quit인 경우 false를 반환
    //getmessage 함수는 메세지가 올때까지 대기, 메세지가 들어 왔다면 true 반환
    //peekmessage 함수는 메세지가 없으면 false 있으면 true 반환
    //게임 루프
    // 이전 getmessage의 대기 상태 유지에서
    //현재 peekmessage의 메세지가 없는 99.99% 상황에서 게임 상황을 처리
    MSG msg;
    while (TRUE)
    {
        if(PeekMessage(&msg, nullptr, 0, 0,PM_REMOVE)) //메세지가 없으면 게임 처리, 메세지가 있으면 메세지 처리
        {
            if (WM_QUIT == msg.message) //종료키를 눌렀을 때 반복문을 아예 나가주는 것을 만들어 줘야함 
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))//메세지가 단축키 메세지 인지 번역
            {
                TranslateMessage(&msg); //기본 메세지를 번역
                DispatchMessage(&msg);  //메세지 순서대로 처리
            }
        }
        else
        {
            //게임 처리
            //게임 업데이트
            //게임 그려줌
            
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    // 윈도우 창의 정보를 저장하기 위한 구조체
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); //구조체의 크기 설정
    
    wcex.style          = CS_HREDRAW | CS_VREDRAW; //윈도우 클래스의 스타일 지정
    wcex.lpfnWndProc    = WndProc;                 //윈도우의 메세지를 처리하는 함수 wndProc 지정
    wcex.cbClsExtra     = 0;                       //윈도우 클래스에서 사용하고자 하는 여분의 메모리양
    wcex.cbWndExtra     = 0;                       //cbClsExtra와 유사하지만 개별 윈도우에서 사용하고자 하는 여분의 메모리양
    wcex.hInstance      = hInstance;               //윈도우 클래스를 등록한 인스턴스 핸들 지정
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWAPI2D));// 윈도우의 아이콘
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);   //윈도우 커서
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);         //윈도우 배경
    wcex.lpszMenuName   = nullptr;//윈도우 메뉴
    wcex.lpszClassName  = szWindowClass;                    
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); //윈도우 작은 아이콘

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우를 생성하는 함수
    hWnd = CreateWindowW(szWindowClass,szTitle,WINSTYLE,WINSTARTX,WINSTARTY,WINSIZEX,WINSIZEY,nullptr,nullptr,hInstance, nullptr);
   //(클래스 이름,윈도우 타이틀 string,윈도우 스타일,윈도우 시작X,윈도우 시작Y,윈도우 가로크기,윈도우 세로크기,부모윈도우,메뉴핸들,프로세스 인스턴스의 핸들, 추가 매개변수)

   if (!hWnd)
   {
      return FALSE;
   }

   
   // 실제 윈도우 크기를 구하기 위해 AdjustWindowRect 사용
   RECT rc;
   rc.left = 0;
   rc.top = 0;
   rc.right = WINSIZEX;
   rc.bottom = WINSIZEY;

   // 실제 창이 크기에 맞게 나온다.
   AdjustWindowRect(&rc, WINSTYLE, false);
   //위 RECT정보로 윈도우 사이즈를 셋팅하자.
   SetWindowPos(hWnd, NULL, WINSTARTX, WINSTARTY, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

POINT g_mousePos = { 100,100 };
POINT g_keyPos = { 0,720 };
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_LBUTTONDOWN:
    {
        //뒤에가 x좌표,앞에가 y좌표 ffff(hiword) ffff(loword)
        g_mousePos.x = LOWORD(lParam);
        g_mousePos.y = HIWORD(lParam);
        InvalidateRect(hWnd, NULL, false);
    }
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
        case'A':
            g_keyPos.x -= 10;
            break;
        case VK_RIGHT:
        case'D':
            g_keyPos.x += 10;
            break;
        case VK_UP:
        case'W':
            g_keyPos.y -= 10;
            break;
        case VK_DOWN:
        case'S':
            g_keyPos.y += 10;
            break;
        }
        InvalidateRect(hWnd, NULL, false);
        break;
    case WM_PAINT: //윈도우의 작업영역이 다시 그려져야 할때 실행됨
        {
            PAINTSTRUCT ps;
            //device context 만들어서 id를 반환
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
           
            HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
            HBRUSH hNewBrush = CreateSolidBrush(RGB(0, 255, 0));

            HPEN hOldPen= (HPEN)SelectObject(hdc, hNewPen);
            HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);

            Ellipse(hdc, g_mousePos.x - 100, g_mousePos.y - 100, g_mousePos.x + 100, g_mousePos.y + 100);
            Rectangle(hdc, g_keyPos.x - 50, g_keyPos.y - 50, g_keyPos.x + 50, g_keyPos.y + 50);
            
            SelectObject(hdc, hOldPen);
            SelectObject(hdc, hOldBrush);

            DeleteObject(hNewPen);
            DeleteObject(hNewBrush);
            
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
