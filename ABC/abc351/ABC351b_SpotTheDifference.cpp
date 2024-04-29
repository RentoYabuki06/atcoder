#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<string> A(109);
vector<string> B(109);

int main()
{
	cin >> N;
	for (int i = 1; i<= N; i++) cin >> A[i];
	for (int i = 1; i<= N; i++) cin >> B[i];
	for (int i = 1; i<= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] != B[i][j])
			{
				cout << i << " " << j + 1 << endl;
				return 0;
			}
		}
	}
	return 0;
}