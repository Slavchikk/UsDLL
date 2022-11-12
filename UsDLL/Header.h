#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
OVERLAPPED ovelapf;
typedef int(_cdecl* MyFunc)();
typedef void(_cdecl* MyFuncTw)(int);
__declspec(dllexport) int GetCountData();
__declspec(dllexport) void VivodData(int);

struct users
{
	char* surname;
	char* name;
	char* midname;
	int age;
};
typedef struct users user;