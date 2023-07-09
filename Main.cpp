#include "MineFunc.h"
#include "Road.h"
#include "Heap.h"
#include "Exception.h"

int main()
{
	try
	{
		int num_of_road;
		int num_of_act;
		char c;
		Road** arr;
		Heap* heap;




		cin >> num_of_road;
		if(num_of_road<0)
			throw Q2EXC();
		if (num_of_road == 0)
			cout << "0" << endl;
		else
		{
			arr = new Road * [num_of_road];
			heap = new Heap(num_of_road);
			cin >> num_of_act;
			if (num_of_act < 1)
				throw Q2EXC();
			for (int i = 0; i < num_of_act; i++)
			{
				cin.ignore();
				c = getchar();
				if(i==0 &&c!='a')
					throw Q2EXC();
				Actions(c, arr, heap, num_of_road);
			}
			delete heap;
			for (int i = 0; i < num_of_road; i++)
			{
				delete arr[i];
			}
			delete[] arr;

		}
		


	}
	catch (Q2EXC& e)
	{
		e.what();
	}
	

}
