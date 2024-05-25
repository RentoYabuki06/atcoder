#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
int P[109];
int P_place[109];
int A[109];
int B[109];
vector<pair<int, int>> people;

int main()
{
	// 入力
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
		people.push_back(make_pair(P[i], i + 1));
	}
	sort(people.begin(), people.end());
	for (int i = 0; i < N; i++)
	{
		P[i] = people[i].second;
	}
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> A[i] >> B[i];
		if (P[A[i] - 1] < P[B[i] - 1]) cout << A[i] << endl;
		else cout << B[i] << endl;
	}
	return 0;
}