#pragma once
#include "MyView.h"
class CTestView :
    public CMyView
{
    MY_DECLARE_DYNCREATE(CTestView)
public:
    CTestView();
    virtual ~CTestView();
};

