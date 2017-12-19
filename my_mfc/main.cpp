#include "TestApp.h"
#include <stdlib.h>

/*
 * 全局实例对象
 */
CTestApp theApp;

/*
 * 全局实例句柄
 */
HINSTANCE g_hInstance;

CMyWinThread* MyGetThread()
{
    return &theApp;
}

int MyWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    int nReturnCode = -1;

    CMyWinThread* pThread = MyGetThread();

    g_hInstance = hInstance;
    if (!pThread->InitInstance())
    {
        nReturnCode = pThread->ExitInstance();
        return nReturnCode;
    }

    //消息循环
    nReturnCode = pThread->Run();
    return nReturnCode;
}

int _tmain(int argc, _TCHAR* argv[])
{
    return MyWinMain(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), SW_SHOWNORMAL);
}
