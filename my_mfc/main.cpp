#include "TestApp.h"
#include "TestView.h"
#include "TestDoc.h"
#include "TestFrame.h"
#include <stdlib.h>

/*
 * ȫ��ʵ������
 */
CTestApp theApp;
CMyWinThread* MyGetThread()
{
    return &theApp;
}

/*
 * ȫ��ʵ�����
 */
HINSTANCE g_hInstance;
HINSTANCE  MyGetInstanceHandle()
{
    return g_hInstance;
}

/*
 * ȫ������ʱ����Ϣ����
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

    //��Ϣѭ��
    nReturnCode = pThread->Run();
    return nReturnCode;
}

int _tmain(int argc, _TCHAR* argv[])
{
    // ����ʱ����ʶ��RTTI��
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
