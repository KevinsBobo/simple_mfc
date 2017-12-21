#include "MyCmdTarget.h"


MY_IMPLEMENT_DYNAMIC(CMyCmdTarget, CMyObject)

CMyCmdTarget::CMyCmdTarget()
{
    MyOutPutDebugString(_T("CMyCmdTarget::CMyCmdTarget()"));
}


CMyCmdTarget::~CMyCmdTarget()
{
    MyOutPutDebugString(_T("CMyCmdTarget::~CMyCmdTarget()"));
}
