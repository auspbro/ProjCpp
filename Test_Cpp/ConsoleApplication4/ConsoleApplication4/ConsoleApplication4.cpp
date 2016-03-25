// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Time
{
public:
	void set_Time();
	void show_Time();
private:
	int hour;
	int minute;
	int sec;
};


int main()
{
	Time t1;
	t1.set_Time();
	t1.show_Time();
	Time t2;
	t2.set_Time();
	t2.show_Time();
    return 0;
}

void Time::set_Time()
{
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::show_Time()
{
	cout << hour << ":" << minute << ":" << sec << endl; 
}
