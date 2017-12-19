#include "TestApp.h"



CTestApp::CTestApp()
{
}


CTestApp::~CTestApp()
{
}

BOOL CTestApp::InitInstance()
{
    //注册窗口
    WNDCLASS wc;
    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)MyWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = MyGetInstanceHandle();
    wc.hIcon = ::LoadIcon((HINSTANCE)NULL,
        IDI_APPLICATION);
    wc.hCursor = ::LoadCursor((HINSTANCE)NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL; // _T("MainMenu");
    wc.lpszClassName = _T("MainWndClass");

    if (!::RegisterClass(&wc))
        return FALSE;


    //创建窗口
    HWND hwndMain = ::CreateWindow(_T("MainWndClass"), _T("Sample"),
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, (HWND)NULL,
        (HMENU)NULL, MyGetInstanceHandle(), (LPVOID)NULL);
    if (!hwndMain)
        return FALSE;


    //显示更新窗口
    ::ShowWindow(hwndMain, SW_SHOWNORMAL);
    ::UpdateWindow(hwndMain);


    return TRUE;
}


/*
 * 窗口回调
 */
LRESULT CALLBACK MyWindowProc(HWND hwnd,INT uMsg, WPARAM wParam, LPARAM lParam )
{
    if (uMsg == WM_DESTROY)
    {
        ::PostQuitMessage(0);
    }

    return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
}
