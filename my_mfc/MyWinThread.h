#pragma once
#include "MyCmdTarget.h"
class CMyWinThread :
    public CMyCmdTarget
{
    MY_DECLARE_DYNAMIC(CMyWinThread)
public:
    CMyWinThread();
    virtual ~CMyWinThread();
    virtual BOOL InitInstance();
    virtual int  ExitInstance();
    /*
     * ��Ϣѭ��
     */
    virtual int  Run();
};

