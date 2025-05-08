#include <iostream>

using namespace std;

int main()
{
	int N, Q;
	int A[200009];
	bool reverse = false;
	cin >> N >> Q;
	for (int i = 1; i<= N; i++) A[i] = i;
	for (int i = 1; i<= Q; i++)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			int x,y;
			cin >> x >> y;
			if (reverse == false)
				A[x] = y;
			else A[N + 1 - x] = y;
		}
		if (query == 2)
		{
			reverse = !reverse;
		}
		if (query == 3)
		{
			int x;
			cin >> x;
			if (reverse == false)
				cout << A[x] << endl;
			else
				cout << A[N + 1 - x] << endl;
		}
	}
	return 0;
}