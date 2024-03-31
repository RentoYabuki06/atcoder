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

		if (sign == "+") A += B;
		else if (sign == "-") A -= B;
		else if (sign == "*") A *= B;
		else if (sign == "/" && B != 0) A /= B;
		else
		{
			cout << "error" << endl;
			break;
		}
		cout << i + 1 << ":" << A << endl;
	}
}
