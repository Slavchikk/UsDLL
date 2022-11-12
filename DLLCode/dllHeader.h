#pragma once
struct users
{
	char* surname;
	char* name;
	char* midname;
	int age;
};

typedef struct users user;

extern "C" __declspec(dllimport) int kolvoData();
extern "C" __declspec(dllimport) void VivodData(int);
extern "C" __declspec(dllimport) void ReadDataSs();
extern "C" __declspec(dllimport) void WriteData(user*, int);

