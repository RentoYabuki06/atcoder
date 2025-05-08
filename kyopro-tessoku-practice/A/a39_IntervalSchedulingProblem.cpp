#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int L[300009];
	int R[300009];
	vector<pair<int,int>> tmp;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> L[i] >> R[i];
		tmp.push_back(make_pair(R[i], L[i]));
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i <= N; i++)
	{
		R[i] = tmp[i - 1].first;
		L[i] = tmp[i - 1].second;
	}


	int current = 0;
	int count = 0;
	for(int i = 1; i <= N; i++)
	{
		if (current <= L[i])
		{
			current = R[i];
			count++;
		}
	}
	cout << count << endl;
	return 0;
}