#include "MyObject.h"



CMyObject::CMyObject()
{
    MyOutPutDebugString(_T("CMyObject::CMyObject()"));
}


CMyObject::~CMyObject()
{
    MyOutPutDebugString(_T("CMyObject::~CMyObject()"));
}

/*
* 在Debug模式下通过控制台输出调试信息
*/
void CMyObject::MyOutPutDebugString(LPCSTR szBuff)
{
#ifdef _DEBUG
    cout << szBuff << endl;
#endif
}
