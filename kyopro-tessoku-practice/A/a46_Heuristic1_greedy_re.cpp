#include <iostream>
#include <cmath>

using namespace std;

int N;
int X[159], Y[159];
bool place[159];

double ft_distance(int a, int b)
{
	return sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]));
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	for (int i = 1; i <= N; i++) place[i] = false;
	place[1] = true;
	int current_place = 1;
	cout << 1 << endl;
	for (int i = 2; i <= N; i++)
	{
		double min_distance = 10000000;
		int next_place = -1;
		for (int j = 1; j <= N; j++)
		{
			if (place[j] == true) continue;
			if (min_distance >= ft_distance(current_place, j))
			{
				min_distance = ft_distance(current_place, j);
				next_place = j;
			}
		}
		place[next_place] = true;
		cout << next_place << endl;
		current_place = next_place;
	}
	cout << 1 << endl;
	return 0;
}