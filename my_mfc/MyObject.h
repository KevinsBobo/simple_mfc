#pragma once

#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

/*
 * ȫ��ʵ�����
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
     * ��Debugģʽ��ͨ������̨���������Ϣ
     */
    virtual void MyOutPutDebugString(LPCSTR szBuff);
};

