#include "MineFunc.h"
void Actions(char c, Road** arr,Heap* heap, int m)
{
	try
	{

		float old;
		float h;
		int r;
		bool Change = false;
		if (c == '\n')
			c = getchar();
		switch (c)
		{
		case 'a':
			for (int i = 0; i < m; i++)
			{
				arr[i] = new Road(i + 1);
				Pair p;
				p.data = arr[i];
				p.priority = arr[i]->getmin_max();
				arr[i]->SetMyLoc(heap->insert(p));

			}
			break;
		case 'b':

			cin >> h;
			if(h<0)
				throw Q2EXC();
			cin >> r;
			if(r>m||r<=0)
				throw Q2EXC();
			old = arr[r - 1]->getmin_max();
			arr[r - 1]->add_new_bridge(h);
			if (old > h)
			{
				heap->FixPriority(arr[r - 1]->GetHeap(), h);
				heap->FixHeap(arr[r - 1]);

			}
			
			break;
		case 'c':
		{
			if (heap->IsEmpthy())
				throw Q2EXC();
			Pair max = heap->GetMax();
			cin >> h;
			if (h < 0)
				throw Q2EXC();
			if (max.priority > h)
				cout << max.data->GetName() << endl;
			else
				cout << "0" << endl;

			break;
		}
		case 'd':
		{
			cin >> r;
			if (r > m || r <= 0)
				throw Q2EXC();
			arr[r - 1]->PrintBridges();
			break;
		}


		default:
		{
			throw Q2EXC();
			break;
		}
		}
	}
	catch (Q2EXC& e)
	{
		e.what();
	}

}