#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> Graph[100009];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i];
		Graph[A[i]].push_back(B[i]);
		Graph[B[i]].push_back(A[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << i << ": {";
		for (int j = 0; j < Graph[i].size(); j++)
		{
			if (j > 0) cout << ", ";
			cout << Graph[i][j];
		}
		cout << "}" << endl;
	}
	return 0;
}