#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, h[100009], min_cost[100009];
vector<int> path;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> h[i];
	min_cost[1] = 0;
	min_cost[2] = abs(h[2] - h[1]);
	for (int i = 3; i <= N; i++)
	{
		min_cost[i] = min(min_cost[i - 1] + abs(h[i] - h[i - 1]), min_cost[i - 2] + abs(h[i] - h[i - 2]));
 	}
	int place = N;
	while(1)
	{
		path.push_back(place);
		if (place == 1)
			break;
		if (min_cost[place] == min_cost[place - 1] + abs(h[place] - h[place - 1]))
			place -= 1;
		else
			place -= 2;
	}
	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	for(int i = 0; i < path.size(); i++)
	{
		if (i > 0) cout << " ";
		cout << path[i];
	}
	cout << endl;
	return 0;
}