// EX01.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>
using namespace std;

//struct point
class point
{
public:
	int x;
	int y;

	//void init()
	//{
	//	x = 0;
	//	y = 0;
	//}
	point()
	{
		x = 0;
		y = 0;
	}

	void output( )
	{
		cout << x << endl << y << endl;
	}
};

int main( )
{
	point pt;
	//pt.x = 0;
	//pt.y = 0;
	//pt.init();
	//cout << pt.x << endl << pt.y << endl;
	pt.output();
	return 0;
}

