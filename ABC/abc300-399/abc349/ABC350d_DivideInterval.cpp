#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

long long L , R;
int Left[69], Right[69];
vector<int, int> output;

int main() {
    cin >> L >> R;

	for (int i = 0; i <= 60; i++)
	{
		if (L & (1 << i)) Left[i] = 1;
	}
	for (int i = 0; i <= 60; i++)
	{
		if (R & (1 << i)) Right[i] = 1;
	}
	
    return 0;
}