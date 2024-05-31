#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> A;
bool terminal[300009];

int main()
{
	cin >> N;
	int front = -1;
	for (int i = 1; i <= N; i++) A.push_back(make_pair(i, N + 1));
	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		if (A[i] == -1) front = i;
	}
	cout << front;
	int Cnum = A[front];
	while (Cnum != N + 1)
	{
		cout << " " << Cnum;
		Cnum = A[Cnum];
	}
	cout << endl;
	return 0;
}