#include <iostream>
#include <vector>

using namespace std;

int N;
int A[300009];

int main()
{
	cin >> N;
	vector<int> people(N + 1, N + 1);
	int front = -1;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		if (A[i] == -1) front = i;
		else people[A[i]] = i;
	}
	cout << front;
	front = people[front];
	while (front < N + 1)
	{
		cout << " " << front;
		front = people[front];
	}
	cout << endl;
	return 0;
}