#include "MyWinApp.h"



CMyWinApp::CMyWinApp()
{
    MyOutPutDebugString(_T("CMyWinApp::CMyWinApp()"));
}


CMyWinApp::~CMyWinApp()
{
    MyOutPutDebugString(_T("CMyWinApp::~CMyWinApp()"));
}

BOOL CMyWinApp::Initstance()
{
    return FALSE;
}

int CMyWinApp::ExitInstance()
{
    return 0;
}
