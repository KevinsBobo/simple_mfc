#include "MyObject.h"


const class CMyRuntimeClass CMyObject::classCMyObject =
{ "CMyObject", sizeof(CMyObject), 0xffff, NULL, NULL, NULL };


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

CMyRuntimeClass * CMyObject::GetRuntimeClass() const
{
    return MY_RUNTIME_CLASS(CMyObject); 
}

BOOL CMyObject::IsKinOf(const CMyRuntimeClass * pClass) const
{
    return FALSE;
}
