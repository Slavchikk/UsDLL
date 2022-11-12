
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <malloc.h>
#include  <windows.h>


#define PATH L"DLLCode.dll"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR nCmdLine, int nCmdShow)
{
	HINSTANCE hMyDll;
	if ((hMyDll = LoadLibrary(PATH)) == NULL) return 1;

	MyFunc myFun = (MyFunc)GetProcAddress(hMyDll,"GetCountData");
	int kol = myFun();

	MyFuncTw res = (MyFuncTw)GetProcAddress(hMyDll, "VivodData");
	res(kol);
	return 0;
}
