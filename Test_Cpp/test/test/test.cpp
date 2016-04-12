// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>		//#包含<stdio.h>

/*

int main(int argc, char* argv[])	//整数类型主函数(整数类型统计参数个数,字符类型*数组指针至字符[])
{
	printf("%d\n", argc);	//格式化输出
	while (argc)	//当(统计参数个数)
		printf("%s\n", argv[--argc]);	//格式化输出
	return 0;	//返回0;正常退出
}
*/

int main(int argc, char const *argv[])
{
	if (argc == 1 || argc > 2)
	{
		printf("请输入想要编辑的文件名如：filename\n");
	}
	if (argc = 2)
	{
		printf("编辑%s\n", argv[1]);
	}
	return 0;
	system("pause");
}