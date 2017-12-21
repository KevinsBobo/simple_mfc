#include "TestApp.h"
#include "TestView.h"
#include "TestDoc.h"
#include "TestFrame.h"
#include <stdlib.h>

/*
 * 全局实例对象
 */
CTestApp theApp;
CMyWinThread* MyGetThread()
{
    return &theApp;
}

/*
 * 全局实例句柄
 */
HINSTANCE g_hInstance;
HINSTANCE  MyGetInstanceHandle()
{
    return g_hInstance;
}

/*
 * 全局运行时类信息链表
 */
list<CMyRuntimeClass*> g_RuntimeList;



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
    // 运行时类型识别（RTTI）
    CTestFrame obj;
    CMyRuntimeClass* pRuntime = obj.GetRuntimeClass();
    while (pRuntime != NULL)
    {
        printf("::%s", pRuntime->m_lpszClassName);
        pRuntime = pRuntime->m_pBaseClass;
    }
    printf("\n");
    return 0;

    return MyWinMain(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), SW_SHOWNORMAL);
}
