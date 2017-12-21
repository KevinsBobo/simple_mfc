#pragma once
#include "MyMainFrame.h"
class CTestFrame :
    public CMyMainFrame
{
    MY_DECLARE_DYNCREATE(CTestFrame)
public:
    CTestFrame();
    virtual ~CTestFrame();
};

