#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<tuple<int, string, int>> store(N);
	for (int i = 0; i < N; i++)
	{
		cin >> get<1>(store[i]) >> get<2>(store[i]);
		get<0>(store[i]) = i;
	}

	sort(store.begin(), store.end(), [](const tuple<int, string, int>&a, const tuple<int, string,int>&b)
	{
		if (get<1>(a) != get<1>(b))
		{
			return get<1>(a) < get<1>(b);
		}
		else
		{
			return get<2>(a) > get<2>(b);
		}
	});

	for (int i = 0; i < N; i++)
	{
		cout << get<0>(store[i]) + 1 << endl;
	}
	return 0;
}