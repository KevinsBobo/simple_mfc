#pragma once
#include "MyCmdTarget.h"
class CMyDocument :
    public CMyCmdTarget
{
    MY_DECLARE_DYNAMIC(CMyDocument)
public:
    CMyDocument();
    virtual ~CMyDocument();
};

