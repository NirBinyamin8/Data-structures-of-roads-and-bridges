#include "Heap.h"
Heap::Heap(int max)
{
	data = new Pair[max];
	maxSize = max;
	heapSize = 0;
	allocate = 1;
}
Heap::~Heap()
{
	if (allocate)
		delete[]data;
	data = NULL;
}
int Heap::Parent(int node)
{
	return (node - 1) / 2;
}
int Heap::Left(int node)
{
	return(2 * node + 1);
}
int Heap::Right(int node)
{
	return(2 * node + 2);
}
void Heap::FixHeap(Road* item)
{
	int node = item->GetHeap();
	int max;
	int left = Left(node);
	int right = Right(node);
	int x;

	if ((left < heapSize) && data[left].priority > data[node].priority)
	{
		max = left;
	}
	else
		max = node;
	if ((right < heapSize) && data[right].priority > data[node].priority)
		max = right;
	if (max != node)
	{
		Road* temp = data[max].data;
		Road* cur = data[node].data;
		swap(data[node], data[max]);
		item->SetMyLoc(max);
		temp->SetMyLoc(node);
		FixHeap(cur);
		FixHeap(temp);
		
	}
	
}
int Heap::insert(Pair item)
{
	int i = heapSize;
	heapSize++;
	if (maxSize+1 == heapSize)
		cout << "EROR ! \n";
		
	

	while ((i > 0) && data[Parent(i)].priority < item.priority)
	{
		data[i] = data[Parent(i)];
		i = Parent(i);

	}
	data[i] = item;
	return i;
}
int Heap::SetNewPrio(float prio, int node)
{
	data[node].priority = prio;
	Pair p = data[node];
	int i = node;
	int parent = Parent(i);

	while ((i > 0) && data[Parent(i)].priority <prio)
	{
		data[i] = data[Parent(i)];
		i = Parent(i);

	}
	data[i] = p;
	return i;

}
Pair Heap::GetMax()
{
	return data[0];
}
void Heap::FixPriority(int node, float p)
{
	data[node].priority = p;
}
bool Heap::IsEmpthy()
{
	return (heapSize ==0);
}
