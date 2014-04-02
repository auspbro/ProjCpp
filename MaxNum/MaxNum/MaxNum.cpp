// MaxNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int i, j;
	int row = 0;
	int colum = 0;
	int max;
	int a[3][4] = { { 2, 1, 5, 343 }, { -2, -34, 74, 0 } };
	max = a[0][0];

	for (i = 0; i <= 2;i++)
	for (j = 0; j <= 3;j++)
	if (a[i][j] > max)
	{
		max = a[i][j];
		row = i;
		colum = j;
	}

	printf("max=%d\nrow=%d\ncolum=%d\n", max, row, colum);
	return 0;
}

