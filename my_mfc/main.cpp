#include "TestApp.h"
#include <stdlib.h>

/*
 * ȫ��ʵ������
 */
CTestApp theApp;

/*
 * ȫ��ʵ�����
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

    //��Ϣѭ��
    nReturnCode = pThread->Run();
    return nReturnCode;
}

int _tmain(int argc, _TCHAR* argv[])
{
    return MyWinMain(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), SW_SHOWNORMAL);
}
