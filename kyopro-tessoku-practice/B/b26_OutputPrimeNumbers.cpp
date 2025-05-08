#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
bool deleted[1000009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) deleted[i] = false;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (deleted[i] == true)
			continue;
		for (int j = i * 2; j <= N; j += i) deleted[j] = true;
	}
	for (int i = 2; i <= N; i++)
	{
		if (deleted[i] == false) cout << i << endl;
	}
	return 0;
}