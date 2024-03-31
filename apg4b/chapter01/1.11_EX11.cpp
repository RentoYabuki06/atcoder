#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A;
	cin >> N >> A;

	for (int i = 0; i < N; i++)
	{
		string sign;
		int B;
		cin >> sign >> B;
		cout << i + 1 << ":";
		if (sign == "+") A += B;
		else if (sign == "-") A -= B;
		else if (sign == "*") A *= B;
		else if (sign == "/")
		{
			if (B != 0) A /= B;
			else
			{
				cout << "error" << endl;
				return 1;
			}
		}
		cout << A << endl;
	}
	return 0;
}
