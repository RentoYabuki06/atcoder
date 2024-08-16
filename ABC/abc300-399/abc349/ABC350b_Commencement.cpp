#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

string S;
int A[109];
int B[109];

int main()
{
	cin >> S;
	for(int i = 0; i <= 100; i++) A[i] = 0;
	for(int i = 0; i <= 100; i++) B[i] = 0;
	for(int i = 0; i < S.size(); i++)
	{
		A[S[i] - 'a']++;
	}
	// for(int i = 0; i < 50; i++) cout <<A[i] << " ";
	for(int i = 0; i < 50; i++)
	{
		B[A[i]]++;
	}
	// cout << endl;
	// for(int i = 0; i < 50; i++) cout <<B[i] << " ";
	for(int i = 1; i <= 100; i++)
	{
		if (!(B[i] == 0 || B[i] == 2))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}