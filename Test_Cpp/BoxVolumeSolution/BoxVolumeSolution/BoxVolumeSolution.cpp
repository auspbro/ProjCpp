// BoxVolumeSolution.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Box
{
public:
	Box();
	Box(int h, int w, int l):height(w), width(w), length(l){};
	//~Box();
	int volume();
private:
	int height;
	int width;
	int length;	
};

Box::Box()
{
	height = 10;
	width = 10;
	length = 10;
}

/*
Box::Box(int h, int w, int l)
{
	height = h;
	width = w;
	length = l;
}
*/

int Box::volume()
{
	return(height * width * length);
}

int main()
{
	//Box box1(12, 25, 30);
	Box box1;
	cout << "The volume of box1 is " << box1.volume() << endl;
	Box box2(15, 30, 21);
	cout << "The volume of box2 is " << box2.volume() << endl;
    return 0;
}

