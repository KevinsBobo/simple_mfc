#pragma once
#include "MyCmdTarget.h"
class CMyWnd :
    public CMyCmdTarget
{
    MY_DECLARE_DYNCREATE(CMyWnd)
public:
    CMyWnd();
    virtual ~CMyWnd();
};

