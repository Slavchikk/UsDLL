#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>


OVERLAPPED ovelapf;
struct users
{
	char* surname;
	char* name;
	char* midname;
	int age;
};
typedef struct users user;
typedef int(_cdecl* MyFunc)();
typedef void(_cdecl* MyFuncTw)(int);
typedef void(_cdecl* MyFuncRead)();
typedef void(_cdecl* MyFuncWrite)(user*, int);





__declspec(dllexport) int kolvoData();
__declspec(dllexport) void VivodData(int);

__declspec(dllexport) void ReadDataSs();
__declspec(dllexport) void WriteData(user* , int );



