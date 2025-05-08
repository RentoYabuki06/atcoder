#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int X[159], Y[159], route[159];
bool visited[159];

double ft_distance(int a, int b)
{
	return sqrt((X[a] - X[b]) *  (X[a] - X[b]) + (Y[a] - Y[b]) *  (Y[a] - Y[b]));
}

int ft_rand(int a, int b)
{
	return a + rand() % (b - a + 1);
}

double ft_rand_double()
{
	return (1.0 * rand()) / RAND_MAX;
}

double ft_get_score()
{
	double sum = 0;
	for (int i = 1; i <= N ; i++) sum += ft_distance(route[i], route[i + 1]);
	return sum;
}


void	ft_local_search()
{
	// 初期解の生成
	for (int i = 1; i <= N ; i++) route[i] = i;
	route[N + 1] = 1;
	double current_score = ft_get_score();

	for (int i = 0; i < 200000; i++)
	{
		// ランダムに右端と左端を決める
		int R = ft_rand(2, N);
		int L = ft_rand(2, N);
		if (R < L) swap(L, R);
		// 配列を逆にしてみる
		reverse(route + L, route + R + 1);
		double new_score = ft_get_score();

		// 焼きなまし法
		// 温度Tが大きいほど許す範囲も大きくなる（初期は大きく）
		double T = 30 - 30 * i / 200000;
		// currentscore < newscore となっていても、確率的に許す
		double probability = exp(min(0.0, (current_score - new_score) / T));
		// スコア改善したらそのまま、しなかったら戻す
		if (ft_rand_double() <= probability) current_score = new_score;
		else reverse(route + L, route + R + 1);
	}
}

int main()
{
	cin >> N;
	for (int i= 1; i <= N; i++) cin >> X[i] >> Y[i];

	ft_local_search();
	for (int i= 1; i <= N + 1; i++) cout << route[i] << endl;
	return 0;
}