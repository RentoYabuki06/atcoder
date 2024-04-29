#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
long long A[200009];
vector<long long> column_ball;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		column_ball.push_back(A[i]);
		int size_column_ball = column_ball.size();
		while (size_column_ball >= 2 && column_ball[size_column_ball - 1] == column_ball[size_column_ball - 2])
		{
			column_ball.pop_back();
			column_ball[size_column_ball - 2]++;
			size_column_ball--;
		}
	}
	cout << column_ball.size() << endl;
	return 0;
}