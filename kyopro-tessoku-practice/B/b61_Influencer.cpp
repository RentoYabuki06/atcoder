#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> Friends[100009];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i];
		Friends[A[i]].push_back(B[i]);
		Friends[B[i]].push_back(A[i]);
	}
	int max_friends = 0;
	int max_friends_student = 0;
	for (int i = 1; i <= N; i++)
	{
		int num_friends = Friends[i].size();
		if (max_friends < num_friends)
		{
			max_friends = num_friends;
			max_friends_student = i;
		}
	}
	cout << max_friends_student << endl;
	return 0;
}