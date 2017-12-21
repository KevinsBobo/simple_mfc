#pragma once

#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <list>
using namespace std;

/*
 * ȫ��ʵ�����
 */
extern HINSTANCE g_hInstance;
HINSTANCE  MyGetInstanceHandle();

class CMyWinThread;
CMyWinThread* MyGetThread();


class CMyRuntimeClass;

/*
 * ��ĳһ���static const classCMyXXX��ΪCMyRuntimeClass*����
 */
 #define MY_RUNTIME_CLASS(class_name) ((CMyRuntimeClass*)(&class_name::class##class_name))

/*
 * ����ʱʶ������
 * ��ĳһ��������м���static const classCMyXXX���ݳ�Ա
 * ��CMyRuntimeClass* GetRuntimeClass����
 */
#define MY_DECLARE_DYNAMIC(class_name) \
public: \
    static const CMyRuntimeClass class##class_name; \
    virtual CMyRuntimeClass* GetRuntimeClass() const; \

/*
 * ����ʱʶ��ʵ��
 * ĳһ��static const classCMyXXX���ݳ�Ա�ĳ�ʼ��
 * ��CMyRuntimeClass* GetRuntimeClass������ʵ��
 */
#define MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
    const CMyRuntimeClass class_name::class##class_name = { \
    #class_name, sizeof(class class_name), wSchema, pfnNew, \
    MY_RUNTIME_CLASS(base_class_name), NULL, class_init }; \
    CMyRuntimeClass* class_name::GetRuntimeClass() const \
    { return MY_RUNTIME_CLASS(class_name); }

/*
 * ����ʱʶ��ʵ��
 * �������Ա��ʼ��������ʵ�ֵĺ����
 */
#define MY_IMPLEMENT_DYNAMIC(class_name, base_class_name) \
    MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)

/*
 * ����ʱ��������
 * ������ʱʶ��Ļ���������static CMyObject* CreateObject��������
 */
#define MY_DECLARE_DYNCREATE(class_name) \
    MY_DECLARE_DYNAMIC(class_name) \
    static CMyObject* CreateObject();

/*
 * ����ʱ����ʵ��
 * ������ʱʶ��Ļ���������static CMyObject* CreateObject����ʵ��
 */
#define MY_IMPLEMENT_DYNCREATE(class_name, base_class_name) \
    CMyObject* class_name::CreateObject() \
    { return new class_name; } \
    MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
    class_name::CreateObject, NULL)


class CMyObject
{
public:
    CMyObject();
    virtual ~CMyObject();
    /*
     * ��Debugģʽ��ͨ������̨���������Ϣ
     */
    virtual void MyOutPutDebugString(LPCSTR szBuff);
public:
    BOOL IsKinOf(const CMyRuntimeClass* pClass) const;
public:
    // ����CMyObjectû�л��࣬�������ݳ�ԱclassCMyObject��û�л���ָ�룬
    // �������ʼ����Ӧ�ú�������Ϊ��ͳһ������˲��ֵ���������ʼ����ʵ��
    // ��ʹ�ú궼�ֹ�����
    static const CMyRuntimeClass classCMyObject;
    virtual CMyRuntimeClass* GetRuntimeClass() const;
};


class CMyRuntimeClass
{
public:
    LPCSTR m_lpszClassName;
    int    m_nObjectSize;
    UINT   m_wSchema;
    CMyObject*       (*m_pfnCreateObject)();
    CMyRuntimeClass* m_pBaseClass;
    CMyRuntimeClass* m_pNextClass;
    void*  pInt;
};


/*
 * ȫ������ʱ����Ϣ����
 */
extern list<CMyRuntimeClass*> g_listRuntime;
typedef list<CMyRuntimeClass*>::iterator itListCMyRtc;

class CMyClassInit
{
public:
    CMyClassInit(CMyRuntimeClass* pRuntimeClass)
    {
        // ��ͷ������ΪԽ�������ʹ�õĸ��ʸ��󣬷�������ͷ�����ױ�����
        g_listRuntime.push_front(pRuntimeClass);
    }
    ~CMyClassInit()
    {
    }
};