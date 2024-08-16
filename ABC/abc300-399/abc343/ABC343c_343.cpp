
#include <iostream>

using namespace std;

bool trueorfalse(long long n)
{
	string s = to_string(n);
	int len = s.length();
	for (int i = 0; i< len / 2; i++)
	{
		if (s[i] != s[len - 1 - i]) return false;
	}
	return true;
}

int main()
{
	long long N;
	cin >> N;
	long long result;
	for(long long i = 1; i <= N; i++)
	{
		long long cube = i * i * i;
		if (cube > N) break;
		if (trueorfalse(cube)) result = cube;
	}
	cout << result << endl;
}