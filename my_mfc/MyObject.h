#pragma once

#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

/*
 * 全局实例句柄
 */
extern HINSTANCE g_hInstance;
inline HINSTANCE  MyGetInstanceHandle()
{
    return g_hInstance;
}

class CMyWinThread;
CMyWinThread* MyGetThread();


class CMyObject
{
public:
    CMyObject();
    virtual ~CMyObject();
    /*
     * 在Debug模式下通过控制台输出调试信息
     */
    virtual void MyOutPutDebugString(LPCSTR szBuff);
};

