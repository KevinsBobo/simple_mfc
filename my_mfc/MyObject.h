#pragma once

#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <list>
using namespace std;

/*
 * 全局实例句柄
 */
extern HINSTANCE g_hInstance;
HINSTANCE  MyGetInstanceHandle();

class CMyWinThread;
CMyWinThread* MyGetThread();


class CMyRuntimeClass;

/*
 * 将某一类的static const classCMyXXX作为CMyRuntimeClass*返回
 */
 #define MY_RUNTIME_CLASS(class_name) ((CMyRuntimeClass*)(&class_name::class##class_name))

/*
 * 运行时识别声明
 * 在某一类的声明中加入static const classCMyXXX数据成员
 * 和CMyRuntimeClass* GetRuntimeClass方法
 */
#define MY_DECLARE_DYNAMIC(class_name) \
public: \
    static const CMyRuntimeClass class##class_name; \
    virtual CMyRuntimeClass* GetRuntimeClass() const; \

/*
 * 运行时识别实现
 * 某一类static const classCMyXXX数据成员的初始化
 * 和CMyRuntimeClass* GetRuntimeClass方法的实现
 */
#define MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
    const CMyRuntimeClass class_name::class##class_name = { \
    #class_name, sizeof(class class_name), wSchema, pfnNew, \
    MY_RUNTIME_CLASS(base_class_name), NULL, class_init }; \
    CMyRuntimeClass* class_name::GetRuntimeClass() const \
    { return MY_RUNTIME_CLASS(class_name); }

/*
 * 运行时识别实现
 * 简化上面成员初始化、方法实现的宏代码
 */
#define MY_IMPLEMENT_DYNAMIC(class_name, base_class_name) \
    MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)

/*
 * 运行时创建声明
 * 在运行时识别的基础上增加static CMyObject* CreateObject方法声明
 */
#define MY_DECLARE_DYNCREATE(class_name) \
    MY_DECLARE_DYNAMIC(class_name) \
    static CMyObject* CreateObject();

/*
 * 运行时创建实现
 * 在运行时识别的基础上增加static CMyObject* CreateObject方法实现
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
     * 在Debug模式下通过控制台输出调试信息
     */
    virtual void MyOutPutDebugString(LPCSTR szBuff);
public:
    BOOL IsKinOf(const CMyRuntimeClass* pClass) const;
public:
    // 由于CMyObject没有基类，所以数据成员classCMyObject中没有基类指针，
    // 所以其初始化不应用宏来做，为了统一，该类此部分的声明、初始化和实现
    // 不使用宏都手工来做
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
 * 全局运行时类信息链表
 */
extern list<CMyRuntimeClass*> g_listRuntime;
typedef list<CMyRuntimeClass*>::iterator itListCMyRtc;

class CMyClassInit
{
public:
    CMyClassInit(CMyRuntimeClass* pRuntimeClass)
    {
        // 向头插是因为越后面的类使用的概率更大，放在链表头更容易遍历到
        g_listRuntime.push_front(pRuntimeClass);
    }
    ~CMyClassInit()
    {
    }
};