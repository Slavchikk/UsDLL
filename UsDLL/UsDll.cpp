#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <malloc.h>
#include  <windows.h>
#define PATH L"DLLCode.dll"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR nCmdLine, int nCmdShow)
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	/*MyFunc MyFuncs = (MyFunc)GetProcAddress(hMyDLL, "kolvoData");
	user* Users =calloc(MyFuncs(), sizeof(user));
	int kol = 0;*/
	MyFuncRead myFun = (MyFuncRead)GetProcAddress(hMyDLL, "ReadDataSS");
	myFun();
	/*int kolvan = 0;
	MyFuncWrite myFunWrite = (MyFuncWrite)GetProcAddress(hMyDLL, "WriteData");
	myFunWrite(Users, kolvan);
	*/
	FreeLibrary(hMyDLL);
	return 0;
}
