#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N ,D, X[200009], Y[200009];
	vector<pair<int, int>> tmp;
	vector<int> work_available;
	cin >> N >> D;
	for (int i = 1; i <= N; i++)
	{
		cin >> X[i] >> Y[i];
		tmp.push_back(make_pair(X[i],Y[i]));
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i <= N; i++)
	{
		X[i] = tmp[i - 1].first;
		Y[i] = tmp[i - 1].second;
	}
	int j = 1;
	int total_money = 0;
	for (int i = 1; i <= D; i++)
	{
		while (i == X[j])
		{
			work_available.push_back(Y[j]);
			j++;
		}
		if (!work_available.empty())
		{
			auto max_elem = max_element(work_available.begin(), work_available.end());
			total_money += *max_elem;
			work_available.erase(max_elem);
		}
	}
	cout << total_money << endl;
	return 0;
}