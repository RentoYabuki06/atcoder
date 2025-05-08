#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A[100009], B[100009], min_time[100009];
vector<int> path;

int main()
{
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];
	min_time[1] = 0;
	min_time[2] = A[2];
	for (int i = 3; i <= N; i++)
	{
		min_time[i] = min(min_time[i - 1] + A[i], min_time[i - 2] + B[i]);
	}
	int place  = N;
	while (1)
	{
		path.push_back(place);
		if (place == 1)
			break;
		if (min_time[place] == min_time[place - 1] + A[place])
			place -= 1;
		else
			place -= 2;
	}
	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	for (int i = 0; i < path.size(); i++)
	{
		if (i > 0) cout << " ";
		cout << path[i];
	}
	cout << endl;
	return 0;
}