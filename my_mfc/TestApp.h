#pragma once
#include "MyWinApp.h"
class CTestApp :
    public CMyWinApp
{
public:
    CTestApp();
    virtual ~CTestApp();
    virtual BOOL InitInstance();
};

/*
 * ´°¿Ú»Øµ÷
 */
LRESULT CALLBACK MyWindowProc(HWND hwnd, INT uMsg, WPARAM wParam, LPARAM lParam);

