// ShowMsg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ShowMsg.h"
#include <conio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

void ShowHelp()
{
	printf("********************************************************************\n");
	printf("** ShowMsg.exe  v0.0.0.1  2016/04/19  by Capt.                    **\n");
	printf("** ShowMsg.exe [ Pass/Fail ]                                      **\n");
	printf("** ShowMsg.exe [ wordColor bkColor message]                       **\n");
	printf("** color: 1-BLUE        2-GREEN       3-CYAN       4-RED          **\n");
	printf("**        5-MAGENTA     6-BROWN       7-LIGHTGRAY  8-DARKGRAY     **\n");
	printf("**        9-LIGHTBLUE  10-LIGHTGREEN 11-LIGHTCYAN 12-LIGHTRED     **\n");
	printf("**       13-LIGHTBLUE  14-YELLOW     15-WHITE                     **\n");
	printf("********************************************************************\n");
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 1;

	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 0;
	}
	else
	{
		// TODO: 在此处为应用程序的行为编写代码。
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 得到Console窗口句柄
		SMALL_RECT rc = { 0,0, 1, 1 };
		SetConsoleWindowInfo(hOut, true, &rc);			// 重置窗口位置和大小
		COORD size = { 80, 300 };
		SetConsoleScreenBufferSize(hOut, size);			// 重新设置缓冲区大小
		SMALL_RECT rc2 = { 0,0, 79, 30 };
		SetConsoleWindowInfo(hOut, true, &rc2);			// 重置窗口位置和大小
														//CloseHandle(hOut);							// 关闭标准输出设备句柄,关闭导致控制台不可用

		if (argc == 2)
		{
			if (!strncmp(argv[1], "pass", strlen(argv[1])))
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
				printf("********************************************************************************");
				printf("***                                                                          ***");
				printf("***    ************         ***           ***********       ***********      ***");
				printf("***    **         **       ** **         **         **     **         **     ***");
				printf("***    **         **      **   **        **                **                ***");
				printf("***    ************      **     **        ***********       ***********      ***");
				printf("***    **               ***********                 **                **     ***");
				printf("***    **              **         **     **         **     **         **     ***");
				printf("***    **             **           **     ***********       ***********      ***");
				printf("***                                                                          ***");
				printf("********************************************************************************");
			}
			else if (!strncmp(argv[1], "fail", strlen(argv[1])))
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_RED);
				printf("********************************************************************************");
				printf("***                                                                          ***");
				printf("***     ************          ***            ******        **                ***");
				printf("***     **                   ** **             **          **                ***");
				printf("***     **                  **   **            **          **                ***");
				printf("***     ************       **     **           **          **                ***");
				printf("***     **                ***********          **          **                ***");
				printf("***     **               **         **         **          **                ***");
				printf("***     **              **           **      ******        ***********       ***");
				printf("***                                                                          ***");
				printf("********************************************************************************");
			}
			else
			{
				ShowHelp();
			}
		}
		else if (argc > 3)
		{
			CString msg = NULL;
			CString SpaceKeys = NULL;
			WORD colorFlag = 0x0F;
			if ((atoi(argv[1])>0) && (atoi(argv[1])<16) && (atoi(argv[2])>0) && (atoi(argv[2])<16))
			{
				colorFlag = atoi(argv[2]) * 16 + atoi(argv[1]);
				SetConsoleTextAttribute(hOut, colorFlag);
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_RED);
				printf("\nSet foreColor or backColor error!\n");
				SetConsoleTextAttribute(hOut, 0x0F);
				return 0;
			}
			for (int i = 3; i < argc; i++)
			{
				msg = msg + " " + CString(argv[i]);
			}
			for (int i = 0; i < 80 - msg.GetLength() - 6; i++)
			{
				SpaceKeys = SpaceKeys + " ";
			}
			printf("********************************************************************************");
			printf("**  ");
			printf("%s%s", msg, SpaceKeys);
			printf("**");
			printf("********************************************************************************");
		}
		else
		{
			ShowHelp();
		}
		SetConsoleTextAttribute(hOut, 0x0F);
	}

	return nRetCode;
}
