#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int A[10];
int B[10];

int main()
{
	int total = 0;
	for (int i = 1; i<= 9; i++) cin >> A[i];
	for (int i = 1; i<= 9; i++) total += A[i];
	for (int i = 1; i<= 8; i++) cin >> B[i];
	for (int i = 1; i<= 8; i++) total -= B[i];

	cout << total + 1 << endl;
	return 0;
}