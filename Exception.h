#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;
class Q2EXC :public exception
{
public:
	void what()
	{
		cout << "invalid input\n";
		exit(1);
	}

};
#endif

