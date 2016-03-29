// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Student
{
public:
	Student(int n, string nam, char s)
	{
		num = n;
		name = nam;
		sex = s;
		cout << "The constructor called" << endl;
	}
	~Student()
	{
		cout << "Desconstructor called" << endl;
	}
	void display()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
	}
private:
	int num;
	char name[10];
	char sex;
	
};

int main()
{
	Student stud1(10001, "Ryan Xue", 'f');
	stud1.display();
	Student sutd2(10002, "Julan Li", 'm');
	sutd2.display();
    return 0;
}

