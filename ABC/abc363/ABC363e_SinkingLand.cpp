#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll H, W, Y;
ll board[1009][1009];
bool sinked[1009][1009];
// vector<pair<ll, ll>> border;
queue<pair<ll, ll>> que[100009];

int main()
{
    // 入力
    cin >> H >> W >> Y;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> board[i][j];
            sinked[i][j] = false;
            if (i == 1 || i == H || j == 1 || j == W)
            {
                que[board[i][j]].push(make_pair(i, j));
                sinked[i][j] = true;
            }
        }
    }

    ll area_island = H * W;

    // BFSのための方向ベクトル
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // 各年ごとの処理
    for (ll year = 1; year <= Y; year++)
    {

        // 幅優先探索
        while (!que[year].empty())
        {
            area_island--;
            pair<ll, ll> p = que[year].front();
            que[year].pop();
            ll x = p.first;
            ll y = p.second;

            for (int d = 0; d < 4; d++)
            {
                ll nx = x + dx[d];
                ll ny = y + dy[d];

                if (nx > 0 && nx <= H && ny > 0 && ny <= W)
                {
                    if (!sinked[nx][ny])
                    {
                        que[max(board[nx][ny], year)].push(make_pair(nx, ny));
                        sinked[nx][ny] = true;
                    }
                }
            }
        }
        // 各年ごとの結果を出力
        cout << area_island << endl;
    }

    return 0;
}
