#ifndef ROADS_H
#define ROADS_H
#include "Pair.h"
#include "List.h"
using namespace std;
#define MAX 100000
#include <iostream>

class Road
{
private:
	int name;
	List bridges;
	float min_max;
	int MyLocHeap;

public:
	Road(int name);
	float getmin_max();
	void setmin_max(int n);
	void add_new_bridge(float h);
	void PrintBridges()const;
	int GetHeap();
	void SetMyLoc(int i);
	int GetName();



	

};


#endif