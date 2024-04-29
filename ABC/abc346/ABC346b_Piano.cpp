#include <iostream>
#include <string>

using namespace std;


int main()
{
	int W, B;
	cin >> W >> B;
	string S = "wbwbwwbwbwbw";
	for (int i = 0; i < 5; i++) S = S + S;

	for (int start = 0; start < 15; start++)
	{
		int count_b = 0;
		int count_w = 0;
		for (int i = start; i < start + W + B; i++)
		{
			if (S[i] == 'w') count_w++;
			if (S[i] == 'b') count_b++;
		}
		if (count_b == B && count_w == W)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}