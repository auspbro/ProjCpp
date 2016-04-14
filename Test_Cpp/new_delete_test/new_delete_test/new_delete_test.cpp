// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "按任意键开始吃内存" << endl;
	system("pause");
	char *p = new char[1024 * 1024 * 1000];
	cout << "哇，我吃了1000M内存，吃的好饱" << endl;
	system("PAUSE");
	delete[]p;
	cout << "现在我吐还1000M" << endl;
	system("PAUSE");
	return 0;
}
