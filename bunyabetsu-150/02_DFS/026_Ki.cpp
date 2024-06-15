#include <iostream>
#include <vector>

using namespace std;

int N, Q;
int A[200009];
int B[200009];
int P[200009];
int X[200009];
int counter[200009];
bool visited[200009];
vector<int> Graph[200009];

void ft_dfs(int place, int add_num)
{
	visited[place] = true;
	counter[place] += add_num;
	for (int i = 0; i < Graph[place].size(); i++)
	{
		int next_place = Graph[place][i];
		if (!visited[next_place]) ft_dfs(next_place, counter[place]);
	}
}

int main()
{
    // 入力
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
	{
		if (i < N)
		{
			cin >> A[i] >> B[i];
			Graph[A[i]].push_back(B[i]);
			Graph[B[i]].push_back(A[i]);
		}
		visited[i] = false;
		counter[i] = 0;
	}
	visited[N] = false;
	counter[0] = 0;
	// それぞれの部分木の加算を記憶
    for (int i = 1; i <= Q; i++) 
	{
		cin >> P[i] >> X[i];
		counter[P[i]] += X[i];
	}
	// 深さ優先探索でカウンターを更新
	ft_dfs(1, 0);
	for (int i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		cout << counter[i];
	}
	cout << endl;
    return 0;
}
