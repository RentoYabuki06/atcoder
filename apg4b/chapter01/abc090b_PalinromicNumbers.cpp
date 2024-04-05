#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int count = 0;
	for (int i = A; i < B + 1; i++)
	{
		string S = to_string(i);
		int len = S.size();
		for (int j = 0; j < S.size() / 2; j++)
		{
			if (S[j] != S[len - j - 1])
			{
				count--;
				break;
			}
		}
		count++;
	}
	cout << count << endl;
	return 0;
}