// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Time
{
public:
	int hour;
	int minute;
	int sec;
	
};

int main()
{
	void set_Time(Time&);
	void show_Time(Time&);
	Time t1;
	set_Time(t1);
	show_Time(t1);
	Time t2;
	set_Time(t2);
	show_Time(t2);
    return 0;
}

void set_Time(Time&t)
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}

void show_Time(Time&t)
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
