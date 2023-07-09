#include "Road.h"
Road::Road(int name) :name(name)
{
	this->min_max = MAX;
	
}
void Road::setmin_max(int n) { min_max = (n); }
float Road::getmin_max()
{
	return(this->min_max);
}
int Road::GetName()
{
	return name;
}
void Road::add_new_bridge(float h)
{
	bridges.addElement(h);
	if ( min_max > h)
	{
		this->min_max = h;
	}
	
}
void Road::PrintBridges() const
{
	bridges.printlist();
}
int Road::GetHeap()
{
	return MyLocHeap;
}
void Road::SetMyLoc(int i)
{
	MyLocHeap = i;
}

