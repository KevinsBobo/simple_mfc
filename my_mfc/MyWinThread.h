#pragma once
#include "MyCmdTarget.h"
class CMyWinThread :
    public CMyCmdTarget
{
public:
    CMyWinThread();
    virtual ~CMyWinThread();
    virtual BOOL InitInstance();
    virtual int  ExitInstance();
    /*
     * ÏûÏ¢Ñ­»·
     */
    virtual int  Run();
};

