// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "���������ʼ���ڴ�" << endl;
	system("pause");
	char *p = new char[1024 * 1024 * 1000];
	cout << "�ۣ��ҳ���1000M�ڴ棬�Եĺñ�" << endl;
	system("PAUSE");
	delete[]p;
	cout << "�������»�1000M" << endl;
	system("PAUSE");
	return 0;
}
