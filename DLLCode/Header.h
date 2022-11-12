#pragma once
struct users
{
	char* surname;
	char* name;
	char* midname;
	int age;
};


extern "C" __declspec(dllimport) int GetCountData();
extern "C" __declspec(dllimport) void VivodData(int);