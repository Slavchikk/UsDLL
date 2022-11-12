#define _CRT_SECURE_NO_WARNINGS
#include "dllHeader.h"
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:

        // Perform any necessary cleanup.
        break;
    }
   
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

int readingFiles(char* str, user* Users, int* kol);
int kolvoData()
{
	HANDLE fileStart;
	fileStart = CreateFile(L"C:\\Users\\КарзиновВА\\source\\repos\\UsDLL\\Users.csv",    // открываемый файл
		GENERIC_READ,          // открываем для чтения
		FILE_SHARE_READ,       // для совместного чтения
		NULL,                  // защита по умолчанию
		OPEN_EXISTING,         // только существующий файл
		FILE_ATTRIBUTE_NORMAL, // обычный файл
		NULL);                 // атрибутов шаблона нет
	if (fileStart == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"При открытие файла возникла ошибка ", L"Ошибка", MB_OK);
		
	}
	DWORD d=0;
	char* str = (char*)calloc(100000, sizeof(char*));
	ReadFile(fileStart, str, 100000, &d, NULL);
	CloseHandle(fileStart);
	int kol = 0;
	int i = 0;
	while (i != 100000)
	{
		if (str[i] == '\n')
		{
			kol++;
		}
		i++;
	}
	
	return kol;
}



void ReadDataSs()
{
	
	user* Users = (user*)calloc(kolvoData(), sizeof(user*));
	//user* Users = calloc(MyFuncs(), sizeof(user));
	int kol = 0;
	HANDLE fileStart;
	fileStart = CreateFile(L"C:\\Users\\КарзиновВА\\source\\repos\\UsDLL\\Users.csv",
		GENERIC_READ,         
		FILE_SHARE_READ,       
		NULL,                
		OPEN_EXISTING,       
		FILE_ATTRIBUTE_NORMAL, 
		NULL);                 
	if (fileStart == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"ошибка", L"ошибка", MB_OK);
		
	}
	DWORD d;
	char* str = (char*)calloc(100000, 1);
	ReadFile(fileStart, str, 100000, &d, NULL);
	
	readingFiles(str, Users, &kol);

	
	WriteData(Users, kol);
}


int readingFiles(char* str, user* Users, int* kol)
{
	int i = 0;
	int k = 0;
	char* stroka = (char*)calloc(100, 1);
	int p = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
		}
		else
		{
			while (str[i] != ';')
			{
				stroka[p] = str[i];
				p++;
				i++;
			}
			i++;
			Users[k].surname = (char*)calloc(p + 1, sizeof(char));
			strncpy(Users[k].surname, stroka, p);
			free(stroka);
			stroka = (char*)calloc(100, 1);
			p = 0;
			while (str[i] != ';')
			{
				stroka[p] = str[i];
				p++;
				i++;
			}
			i++;
			Users[k].name = (char*)calloc(p + 1, sizeof(char));
			strncpy(Users[k].name, stroka, p);
			free(stroka);
			stroka = (char*)calloc(100, 1);
			p = 0;
			while (str[i] != ';')
			{
				stroka[p] = str[i];
				p++;
				i++;
			}
			i++;
			Users[k].midname = (char*)calloc(p + 1, sizeof(char));
			strncpy(Users[k].midname, stroka, p);
			free(stroka);
			stroka = (char*)calloc(100, 1);
			p = 0;
			while (str[i] != '\"')
			{
				stroka[p] = str[i];
				p++;
				i++;
			}
			i++;
			Users[k].age = atoi(stroka);
			free(stroka);
			stroka = (char*)calloc(100, 1);
			p = 0;
			i += 2;
			k++;
		}
	}
	*kol = k;

	return 0;
}
void VivodData(int kol)
{

	HANDLE fileResult;
	fileResult = CreateFile(L"..\\Result.txt",    // открываемый файл
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (fileResult == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"При выводе", L"Ошибка", MB_OK);
	}
	DWORD  d = 0;
	OVERLAPPED olf = { 0 };//позиция
	char* strNew = (char*)calloc(100000, sizeof(char*));
	sprintf(strNew, "Всего пользователей: %d", kol);
	olf.Offset = 0xFFFFFFFF;
	olf.OffsetHigh = 0xFFFFFFFF;
	WriteFile(fileResult, strNew, strlen(strNew), &d, &olf);
	CloseHandle(fileResult);
}


void WriteData(user* Users, int kol) 
{
	HANDLE fileResult = CreateFile(L"C:\\Users\\КарзиновВА\\source\\repos\\UsDLL\\UpdateUser.csv",
		GENERIC_WRITE,        
		FILE_SHARE_WRITE,      
		NULL,                 
		CREATE_ALWAYS,       
		FILE_ATTRIBUTE_HIDDEN, 
		NULL);                 
	int i = 0;
	DWORD d;
	char* str;
	while (i != kol)
	{
		str = (char*)calloc(100, sizeof(char));
		sprintf(str, "%s;", Users[i].surname);
		WriteFile(fileResult, str, strlen(str), &d, NULL);
		free(str);
		str = (char*)calloc(100, sizeof(char));
		sprintf(str, "%s;", Users[i].name);
		WriteFile(fileResult, str, strlen(str), &d, NULL);
		free(str);
		str = (char*)calloc(100, sizeof(char));
		sprintf(str, "%s;", Users[i].midname);
		WriteFile(fileResult, str, strlen(str), &d, NULL);
		free(str);
		str = (char*)calloc(100, sizeof(char));
		sprintf(str, "%d\n", Users[i].age);
		WriteFile(fileResult, str, strlen(str), &d, NULL);
		i++;
	}
	CloseHandle(fileResult);
}
