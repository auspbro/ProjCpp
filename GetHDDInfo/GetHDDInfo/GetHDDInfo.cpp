// GetHDDInfo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Windows.h"
#include  <conio.h>
#include "Pandora.h"
#include "Corolla.h"

#pragma  comment(lib,"Pandora.lib")
#pragma  comment(lib,"Corolla.lib")

#define PROGRAM_NAME "Get HDD Information"
#define PROGRAM_VERSION "1.0.0.0"
#define MODIFY_DATE "2016/04/11"

char Program_Name[100];
int OutputFlag;
char HDD_Model[256];
char HDD_Firmware[256];
char HDD_Size[256];
char HDD_SerialNumber[256];

void GetHDDInformation()
{
	char Buff[256];
	int i, j, k;

	GetOneInforByWMI("Win32_DiskDrive", "PNPDeviceID", 1, Buff);
	for (i = 0; i < 256; i++)
	{
		j = i + 8;
		if (Buff[j] == '_' && Buff[j + 1] == '_')
		{
			HDD_Model[i] = '\0';
			break;
		}
		else
			HDD_Model[i] = Buff[j];
	}

	for (;;)
	{
		j++;
		if (Buff[j] != '_')
			break;
	}

	for (k = 0; k < 256; k++)
	{
		if (Buff[j] == '\\')
		{
			HDD_Firmware[k] = '\0';
			break;
		}
		else
			HDD_Firmware[k] = Buff[j];

		j++;
	}

	for (;;)
	{
		k--;
		if (HDD_Firmware[k] == '_')
			HDD_Firmware[k] = '\0';
		else
			break;
	}

	GetOneInforByWMI("Win32_DiskDrive", "Size", 1, Buff);
	strncpy_s(HDD_Size, Buff, strlen(Buff) - 6);

	GetOneInforByWMI("Win32_PhysicalMedia", "SerialNumber", 1, HDD_SerialNumber);
}

void OutputResult()
{
	if (OutputFlag == 1)
	{
		printf("HDD MD : %s\n", HDD_Model);

		printf("HDD FW : %s\n", HDD_Firmware);

		printf("HDD SN : %s\n", HDD_SerialNumber);

		printf("HDD SZ : %s\n", HDD_Size);
	}
	else if (OutputFlag == 2)
	{
		printf("SET HDD_MD=%s\n", HDD_Model);

		printf("SET HDD_FW=%s\n", HDD_Firmware);

		printf("SET HDD_SN=%s\n", HDD_SerialNumber);

		printf("SET HDD_SZ=%s\n", HDD_Size);
	}
}

void ShowHelp()
{
	ShowAbout(PROGRAM_NAME, PROGRAM_VERSION, MODIFY_DATE);

	printf("Usage:\n");
	printf("    %s  [/show]  [/set]  [/?]\n", Program_Name);
	printf("    /show  Show HDD Model,Firmware,SerialNumber,Size \n");
	printf("    /set   Set  HDD Model,Firmware,SerialNumber,Size \n");
	printf("    /?     Help\n");
}
int _tmain(int argc, _TCHAR* argv[])
{

	strncpy(Program_Name, argv[0], strlen(argv[0]));

	if (argc == 2)
	{
		if (!stricmp(argv[1], "/show"))
			OutputFlag = 1;
		else if (!stricmp(argv[1], "/set"))
			OutputFlag = 2;
		else
		{
			ShowHelp();
			return 0;
		}
	}
	else
	{
		ShowHelp();
		return 0;
	}

	GetHDDInformation();
	OutputResult();

	return 0;
}



