#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int X[159], Y[159];
int place[159];

double ft_distance(int a, int b)
{
	return sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]));
}

double ft_total_score()
{
	double sum;
	for(int i = 1; i <= N; i++)
	{
		sum += ft_distance(place[i], place[i + 1]);
	}
	return sum;
}

int ft_rand(int a, int b)
{
	return (rand() % (b - a + 1)) + a;
}

void ft_yamanobori()
{
	double min_distance = ft_total_score();
	for (int i = 0; i < 200000; i++)
	{
		int R = ft_rand(2, N);
		int L = ft_rand(2, N);
		if (L > R) swap(R, L);
		// ランダムな区間を反転
		reverse(place + L, place + R + 1);
		// 短くなったら採用
		if (min_distance >= ft_total_score())
			min_distance = ft_total_score();
		else
			reverse(place + L, place + R + 1); // 短くならなかったら元に戻す
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	for (int i = 1; i <= N; i++) place[i] = i;
	place [N + 1] = 1;
	ft_yamanobori();
	for (int i = 1; i <= N + 1; i++) cout << place[i] << endl;
	return 0;
}