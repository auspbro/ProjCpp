// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
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
	void set_Time(Time&, int hour = 0, int minute = 0, int sec = 0);
	void show_Time(Time&);
	Time t1;
	set_Time(t1, 12, 34, 56);
	show_Time(t1);
	Time t2;
	set_Time(t2);
	show_Time(t2);
    return 0;
}

void set_Time(Time&t, int hour, int minute, int sec)
{
	t.hour = hour;
	t.minute = minute;
	t.sec = sec;
}

void show_Time(Time&t)
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}