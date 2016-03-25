// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Array_Max
{
public:
	void set_value();
	void max_value();
	void show_value();
private:
	int array[10];
	int max;

};

void Array_Max::set_value()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> array[i];
	}
}

void Array_Max::max_value()
{
	int i;
	max = array[0];
	for (i = 1; i < 10; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
}

void Array_Max::show_value()
{
	cout << "max=" << max;
}


int main()
{
	Array_Max arrmax;
	arrmax.set_value();
	arrmax.max_value();
	arrmax.show_value();
    return 0;
}

