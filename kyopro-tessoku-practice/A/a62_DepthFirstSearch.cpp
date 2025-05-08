#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> Graph[100009];
bool visited[100009];

void	ft_dfs(int place)
{
	visited[place] = true;
	for (int i = 0; i < Graph[place].size(); i++)
	{
		int new_place = Graph[place][i];
		if (visited[new_place] == false) ft_dfs(new_place);
	}
	return ;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i];
		Graph[A[i]].push_back(B[i]);
		Graph[B[i]].push_back(A[i]);
	}
	// 全ての頂点を未踏に初期化
	for (int i = 1; i <= N; i++) visited[i] = false;
	// 1つ目の頂点から再帰関数による深さ優先探索
	ft_dfs(1);
	// 出力
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
		{
			cout << "The graph is not connected." << endl;
			return 0;
		}
	}
	cout << "The graph is connected." << endl;
	return 0;
}