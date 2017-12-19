#pragma once
#include "MyWinThread.h"
class CMyWinApp :
    public CMyWinThread
{
public:
    CMyWinApp();
    virtual ~CMyWinApp();
    virtual BOOL Initstance();
    virtual int  ExitInstance();
};

