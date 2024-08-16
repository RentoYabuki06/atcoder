#include <iostream>

using namespace std;

int N;
int X[109];
int Y[109];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	int total_takahashi = 0;
	int total_aoki = 0;
	for (int i = 1; i <= N; i++)
	{
		total_takahashi += X[i];
		total_aoki += Y[i];
	}
	if (total_takahashi == total_aoki) cout << "Draw" << endl;
	else if (total_takahashi > total_aoki) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	return 0;
}