#include <iostream>

using namespace std;

int H, W, Q;
int X[1509][1509], cum[1509][1509];
int A[1000009], B[1000009], C[1000009], D[1000009];

int main()
{
	cin >> H >> W;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> X[i][j];
			cum[i][j] = 0;
		}
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
	//横方向の累積和
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cum[i][j] = cum[i][j - 1] + X[i][j];
		}
	}
	//縦方向の累積和
	for (int j = 1; j <= W; j++)
	{
		for (int i = 1; i <= H; i++)
		{
			cum[i][j] += cum[i - 1][j];
		}
	}
	for (int i = 1; i <= Q; i++)
	{
		int sum = 0;
		sum = cum[C[i]][D[i]] - cum[C[i]][B[i] - 1] - cum[A[i] - 1][D[i]] + cum[A[i] - 1][B[i] - 1];
		cout << sum << endl;
	}
	return 0;
}