#include "TestApp.h"
#include "TestView.h"
#include "TestDoc.h"
#include "TestFrame.h"
#include <stdlib.h>

/*
 * ȫ��ʵ������
 */
CTestApp theApp;
CMyWinThread* MyGetThread()
{
    return &theApp;
}

/*
 * ȫ��ʵ�����
 */
HINSTANCE g_hInstance;
HINSTANCE  MyGetInstanceHandle()
{
    return g_hInstance;
}

/*
 * ȫ������ʱ����Ϣ����
 */
list<CMyRuntimeClass*> g_RuntimeList;
typedef list<CMyRuntimeClass*>::iterator itListCMyRtc;



/*
 * ����������̬��������
 */
CMyObject *CreateMyObj(const char *pClsName)
{
  //����
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
 * ����pRuntimeClass��̬��������
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

    //��Ϣѭ��
    nReturnCode = pThread->Run();
    return nReturnCode;
}


int _tmain(int argc, _TCHAR* argv[])
{
    // ����ʱ����ʶ��RTTI��
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
