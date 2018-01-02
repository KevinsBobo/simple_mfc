#include "TestApp.h"
#include "TestView.h"
#include "TestDoc.h"
#include "TestFrame.h"
#include <stdlib.h>

/*
 * 全局实例对象
 */
CTestApp theApp;
CMyWinThread* MyGetThread()
{
    return &theApp;
}

/*
 * 全局实例句柄
 */
HINSTANCE g_hInstance;
HINSTANCE  MyGetInstanceHandle()
{
    return g_hInstance;
}

/*
 * 全局运行时类信息链表
 */
list<CMyRuntimeClass*> g_RuntimeList;
typedef list<CMyRuntimeClass*>::iterator itListCMyRtc;



/*
 * 根据类名动态创建对象
 */
CMyObject *CreateMyObj(const char *pClsName)
{
  //遍历
  for (itListCMyRtc it = g_RuntimeList.begin();
       it != g_RuntimeList.end();
       it++)
  {
    CMyRuntimeClass *pRuntimeClass = *it;
    if (strcmp(pRuntimeClass->m_lpszClassName, pClsName) == 0)
    {
      if (pRuntimeClass->m_pfnCreateObject != NULL)
        return pRuntimeClass->m_pfnCreateObject();
    }
  }
  
  return NULL;
}


/*
 * 根据pRuntimeClass动态创建对象
 */
void CreateObj(CMyRuntimeClass *pRuntimeClass)
{
  pRuntimeClass->m_pfnCreateObject();
}  


int MyWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    int nReturnCode = -1;

    CMyWinThread* pThread = MyGetThread();

    g_hInstance = hInstance;
    if (!pThread->InitInstance())
    {
        nReturnCode = pThread->ExitInstance();
        return nReturnCode;
    }

    //消息循环
    nReturnCode = pThread->Run();
    return nReturnCode;
}


int _tmain(int argc, _TCHAR* argv[])
{
    // 运行时类型识别（RTTI）
    // CTestFrame obj;
    // CMyRuntimeClass* pRuntime = obj.GetRuntimeClass();
    // while (pRuntime != NULL)
    // {
    //     printf("::%s", pRuntime->m_lpszClassName);
    //     pRuntime = pRuntime->m_pBaseClass;
    // }
    // printf("\n");
    // return 0;

    return MyWinMain(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), SW_SHOWNORMAL);
}
