#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

int N;
string S;
int A[100009];
vector<int> Graph[10009];

int main()
{
	cin >> N;
	int count = 0;
	for (int i = 1; i <= 2 * N ; i++)cin >> A[i];
	for (int i = 1; i <= 2 * N - 2 ; i++)
	{
		if (A[i] == A[i + 2]) count++;
	}
	cout << count << endl;
    return 0;
}
