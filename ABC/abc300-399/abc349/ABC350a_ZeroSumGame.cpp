#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int A[109];

int main()
{
	cin >> N;
	int sum = 0;
	for (int i = 1; i <= N-1; i++) 
	{
		cin >> A[i];
		sum += A[i];
	}
	cout << -sum << endl;
}