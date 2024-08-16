#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string S;

int main()
{
	cin >> N >> M >> S;
	int num_muji = M;
	int num_logo = 0;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (S[i] == '0')
		{
			num_muji = M;
			num_logo = 0;
		}
		else if (S[i] == '1')
		{
			if (num_muji > 0) num_muji--;
			else num_logo++;
		}
		else num_logo++;
		ans = max(ans, num_logo);
	}
	cout << ans << endl;
	return 0;
}