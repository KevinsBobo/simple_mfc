#include "MyWinThread.h"



CMyWinThread::CMyWinThread()
{
    MyOutPutDebugString(_T("CMyWinThread::CMyWinThread()"));
}


CMyWinThread::~CMyWinThread()
{
    MyOutPutDebugString(_T("CMyWinThread::~CMyWinThread()"));
}

BOOL CMyWinThread::InitInstance()
{
    return FALSE;
}

int CMyWinThread::ExitInstance()
{
    return 0;
}

/*
 * ÏûÏ¢Ñ­»·
 */
int CMyWinThread::Run()
{
    MSG msg;
    BOOL bRet;

    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            break;
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}
