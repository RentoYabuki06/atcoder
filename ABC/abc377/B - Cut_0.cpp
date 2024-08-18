#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

float N;

int main()
{
    cin >> N;
    string S = to_string(N);

	int i = 0;
    while (true)
    {
		if (S[i] == '.')
		{
			if (S[i+1] == '0' && S[i+2] == '0' && S[i+3] == '0')
			{
				cout << endl;
				return 0;
			}
			cout << S[i];
			break;
		}
		cout << S[i];
		i++;
    }
	i++;
	if (S[i+1] == '0' && S[i+2] == '0')
	{
		cout << S[i];
		cout << endl;
		return 0;
	}
	if (S[i+2] == '0')
	{
		cout << S[i] << S[i+1];
		cout << endl;
		return 0;
	}
	cout << S[i] << S[i+1] << S[i+2];
    cout << endl;
    return 0;
}
