#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int N, A;
	cin >> N >> A;
	int T[109];
	int total = 0;
	for (int i = 1; i<= N; i++) 
	{
		cin >> T[i];
		if (total <= T[i]) total = T[i] + A;
		else total += A;
		if (i > 1) cout << " ";
		cout << total;
	}
	cout << endl;
	return 0;
}