#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int student[200009];
	cin >> N >> M;
	for(int i = 1; i <= N; i++) student[i] = M;
	for(int i = 1; i <= M; i++)
	{
		int A;
		cin >> A;
		student[A]--;
	}
	for(int i = 1; i <= N; i++) cout << student[i] << endl;
	return 0;
}