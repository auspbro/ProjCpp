// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>		//#����<stdio.h>

/*

int main(int argc, char* argv[])	//��������������(��������ͳ�Ʋ�������,�ַ�����*����ָ�����ַ�[])
{
	printf("%d\n", argc);	//��ʽ�����
	while (argc)	//��(ͳ�Ʋ�������)
		printf("%s\n", argv[--argc]);	//��ʽ�����
	return 0;	//����0;�����˳�
}
*/

int main(int argc, char const *argv[])
{
	if (argc == 1 || argc > 2)
	{
		printf("��������Ҫ�༭���ļ����磺filename\n");
	}
	if (argc = 2)
	{
		printf("�༭%s\n", argv[1]);
	}
	return 0;
	system("pause");
}