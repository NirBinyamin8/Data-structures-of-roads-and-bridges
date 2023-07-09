#ifndef HEAP_H
#define HEAP_H
#include "Road.h"
#include "Pair.h"
class Heap {
private:
	Pair* data;
	int maxSize;
	int heapSize;
	int allocate = 0;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
public:
	Heap(int max);
	~Heap();
	Road* max();
	int insert(Pair item);
	int SetNewPrio(float prio, int node);
	void FixHeap(Road* item);
	Pair GetMax();
	void FixPriority(int node, float p);
	bool IsEmpthy();

};
#endif

