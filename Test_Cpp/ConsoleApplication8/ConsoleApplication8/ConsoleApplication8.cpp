// ConsoleApplication8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Time
{	
public:
	void input();
	void output();
private:
	int hour;
	int minute;
	int sec;
};

int main()
{
	Time t1;
	t1.input();
	t1.output();
	return 0;
}

void Time::input()
{
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::output()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}

