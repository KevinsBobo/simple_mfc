#pragma once
#include "MyWinThread.h"
class CMyWinApp :
    public CMyWinThread
{
    MY_DECLARE_DYNAMIC(CMyWinApp)
public:
    CMyWinApp();
    virtual ~CMyWinApp();
    virtual BOOL Initstance();
    virtual int  ExitInstance();
};

