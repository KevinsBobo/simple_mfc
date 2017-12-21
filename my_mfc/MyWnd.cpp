#include "MyWnd.h"

MY_IMPLEMENT_DYNCREATE(CMyWnd, CMyCmdTarget)


CMyWnd::CMyWnd()
{
    MyOutPutDebugString(_T("CMyWnd::CMyWnd()"));
}


CMyWnd::~CMyWnd()
{
    MyOutPutDebugString(_T("CMyWnd::~CMyWnd()"));
}
