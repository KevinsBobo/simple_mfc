#pragma once
#include "MyObject.h"
class CMyCmdTarget :
    public CMyObject
{
    MY_DECLARE_DYNAMIC(CMyCmdTarget)
public:
    CMyCmdTarget();
    virtual ~CMyCmdTarget();
};

