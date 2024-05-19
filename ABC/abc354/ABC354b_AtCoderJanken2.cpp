#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int N;
int C[109];
vector<string> S(109);
vector<pair<string, int>> member;

int main()
{
	cin >> N;
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i] >> C[i];
		member.push_back(make_pair(S[i], C[i]));
		total += C[i]; 
	}
	sort(member.begin(), member.end());
	int mod = total % N;
	cout << member[mod].first << endl;
	return 0;
}

