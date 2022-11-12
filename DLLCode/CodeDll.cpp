#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
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

int GetCountData()
{
	HANDLE fileStart;
	fileStart = CreateFile(L"..\\Users.csv",    // открываемый файл
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
	DWORD d;
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
		MessageBox(NULL, L"При записи в файл возникла ошибка", L"Окно программы", MB_OK);
	}
	DWORD  d = 0;
	OVERLAPPED olf = { 0 };//позиция
	char* strNew = (char*)calloc(100000, sizeof(char*));
	sprintf(strNew, "Всего строк: %d", kol);
	olf.Offset = 0xFFFFFFFF;
	olf.OffsetHigh = 0xFFFFFFFF;
	WriteFile(fileResult, strNew, strlen(strNew), &d, &olf);
}

