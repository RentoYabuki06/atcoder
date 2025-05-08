#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	char C;
	string S;
	cin >> N >> C >> S;
	int total = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'B') total += 1; 
		if (S[i] == 'R') total += 2; 
	}
	if (C == 'W' && total % 3 == 0)
	{
		cout << "Yes" << endl;
		return 0;
	}
	if (C == 'B' && total % 3 == 1) 
	{
		cout << "Yes" << endl;
		return 0;
	}
	if (C == 'R' && total % 3 == 2) 
	{
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl; 
	return 0;
}