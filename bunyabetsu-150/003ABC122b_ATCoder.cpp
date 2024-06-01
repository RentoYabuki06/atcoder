#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
int ACGT[19];

int main()
{
	cin >> S;
	int long_ACGT = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T')
		{
			if (i == 0) ACGT[i]  = 1;
			else ACGT[i] = ACGT[i - 1] + 1;
		}
		else ACGT[i]  = 0;
		long_ACGT = max(long_ACGT, ACGT[i]);
	}
	cout << long_ACGT << endl;
	return 0;
}