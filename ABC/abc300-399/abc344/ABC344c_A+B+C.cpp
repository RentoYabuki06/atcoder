#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,L,Q;
int A[109];
int B[109];
int C[109];
int X[200009];
int AB[10009];
vector<int> ABC;

int main()
{
	// 入力
	cin	>> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> B[i];
	cin >> L;
	for (int i = 0; i < L; i++) cin >> C[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> X[i];
	// A, Bからひとつずつ取ってできる数を列挙
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < L; k++) ABC.push_back(A[i] + B[j] + C[k]);
		}
	}
	// ソート
	sort(ABC.begin(), ABC.end());
	int min = ABC[0];
	int max = ABC[ABC.size() - 1];
	for (int i = 0; i < Q; i++)
	{
		if (X[i] < min || max < X[i])
		{
			cout << "No" << endl;
			continue;
		}
		auto itr = lower_bound(ABC.begin(), ABC.end(), X[i]);
		if (*itr == X[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}