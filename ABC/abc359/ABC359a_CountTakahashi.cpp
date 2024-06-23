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
	int count = 0;
	cin >> N;
	for (int i = 1; i <= N ; i++)
	{
		cin >> S;
		if (S == "Takahashi") count++;
	}
	cout << count << endl;
    return 0;
}
