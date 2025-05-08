#include <iostream>

using namespace std;

int T;
int P[109], Q[109], R[109];
int X[29];

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) cin >> P[i] >> Q[i] >> R[i];
	for (int i = 1; i <= 20; i++) X[i] = 0;
	for (int i = 1; i <= T; i++)
	{
		int score_incre = 0;
		int score_decre = 0;
		X[P[i]]++;
		X[Q[i]]++;
		X[R[i]]++;
		for (int i = 1; i <= 20; i++)
		{
			if (X[i] == 0) score_incre++;
		}
		X[P[i]] -= 2;
		X[Q[i]] -= 2;
		X[R[i]] -= 2;
		for (int i = 1; i <= 20; i++)
		{
			if (X[i] == 0) score_decre++;
		}
		if (score_decre < score_incre)
		{
			X[P[i]] += 2;
			X[Q[i]] += 2;
			X[R[i]] += 2;
			cout << "A" << endl;
		}
		else cout << "B" << endl;
	}
	return 0;
}