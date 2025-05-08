#include <iostream>
#include <cmath>

using namespace std;

int N;
int X[159], Y[159], route[159];
bool visited[159];

double ft_distance(int a, int b)
{
	return sqrt((X[a] - X[b]) *  (X[a] - X[b]) + (Y[a] - Y[b]) *  (Y[a] - Y[b]));
}

void	ft_donyoku()
{
	for (int i= 1; i <= N; i++) visited[i] = false;
	route[1] = 1;
	visited[1] = true;
	int current = 1;

	for (int i = 2; i <= N; i++)
	{
		double min_distance = 1000000.0;
		int next_place = -1;
		for (int j= 1; j <= N; j++)
		{
			if (visited[j] == true) continue;
			double new_distance = ft_distance(current, j);
			if (min_distance > new_distance)
			{
				min_distance = new_distance;
				next_place = j;
			}
		}
		visited[next_place] = true;
		route[i] = next_place;
		current = next_place;
	}
	route[N + 1] = 1;
}


int main()
{
	cin >> N;
	for (int i= 1; i <= N; i++) cin >> X[i] >> Y[i];

	ft_donyoku();
	for (int i= 1; i <= N + 1; i++) cout << route[i] << endl;
	return 0;
}