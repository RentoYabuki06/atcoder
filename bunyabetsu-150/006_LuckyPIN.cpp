#include <iostream>
#include <string>

using namespace std;

int N;
string S;
int lucky_num[30009];

int ft_next_num(int current_place, int target_num)
{
	while (current_place < S.size() && lucky_num[current_place] != target_num)
	{
		current_place++;
	}
	if (current_place == S.size()) return -1;
	return current_place;
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < S.size(); i++) lucky_num[i] = S[i] - '0';
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		int first_place = ft_next_num(0, i);
		if (first_place == -1) continue;
		for (int j = 0; j < 10; j++)
		{
			int second_place = ft_next_num(first_place + 1, j);
			if (second_place == -1) continue;
			for (int k = 0; k < 10; k++)
			{
				int third_place = ft_next_num(second_place + 1, k);
				if (third_place != -1) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
