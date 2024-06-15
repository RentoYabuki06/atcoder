#include <iostream>
#include <vector>

using namespace std;

int N, U, K, V, count_num;
vector<int> Graph[109];
int discovery[109];
int final[109];

void ft_dfs(int place)
{
    discovery[place] = ++count_num;  // 発見時刻を設定
    for (int i = 0; i < Graph[place].size(); i++)
    {
        int next_place = Graph[place][i];
        if (discovery[next_place] == -1) ft_dfs(next_place);
    }
    final[place] = ++count_num;  // 終了時刻を設定
}

int main()
{
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> U >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> V;
            Graph[U].push_back(V);
        }
    }
    // 初期化
    for (int i = 1; i <= N; i++)
    {
        discovery[i] = -1;
        final[i] = -1;
    }
    count_num = 0;
    // 深さ優先探索を全てのノードから開始
    for (int i = 1; i <= N; i++)
    {
        if (discovery[i] == -1) ft_dfs(i);
    }
    // 出力
    for (int i = 1; i <= N; i++)
    {
        cout << i << " " << discovery[i] << " " << final[i] << endl;
    }
    return 0;
}
