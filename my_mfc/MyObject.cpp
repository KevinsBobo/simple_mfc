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
* ��Debugģʽ��ͨ������̨���������Ϣ
*/
void CMyObject::MyOutPutDebugString(LPCSTR szBuff)
{
#ifdef _DEBUG
    cout << szBuff << endl;
#endif
}
