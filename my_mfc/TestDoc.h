#pragma once
#include "MyDocument.h"
class CTestDoc :
    public CMyDocument
{
    MY_DECLARE_DYNCREATE(CTestDoc)
public:
    CTestDoc();
    virtual ~CTestDoc();
};

