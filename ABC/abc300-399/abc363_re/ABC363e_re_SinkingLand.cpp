#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll H, W, Y;
ll board[1009][1009];
bool boarder[1009][1009];
queue<pair<ll, ll>> que[100009];

int main()
{
    cin >> H >> W >> Y;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> board[i][j];
            boarder[i][j] = false;
            if (i == 1 || i == H || j == 1 || j == W)
            {
                boarder[i][j] = true;
                que[board[i][j]].push(make_pair(i, j));
            }
        }
    }
    ll ans = H * W;
    ll dx[4] = {1, -1, 0, 0};
    ll dy[4] = {0, 0, 1, -1};
    for (ll year = 1; year <= Y; year++)
    {
		// que[year]に入っているのは今年沈むマスのみ
        while (!que[year].empty())
        {
            ans--;
            pair<ll, ll> tmp = que[year].front();
            que[year].pop();
            ll x = tmp.first;
            ll y = tmp.second;
            for (int l = 0; l < 4; l++)
            {
                ll nx = x + dx[l];
                ll ny = y + dy[l];
                if (nx > 0 && nx <= H && ny > 0 && ny <= W)
                {
                    if (!boarder[nx][ny])
                    {
                        boarder[nx][ny] = true;
						// year > board[nx][ny]だったらこのyearに沈む
                        que[max(year, board[nx][ny])].push(make_pair(nx, ny));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
