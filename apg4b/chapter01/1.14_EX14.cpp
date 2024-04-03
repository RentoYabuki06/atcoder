#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int max_num, min_num;

	max_num = max(max(A, B), C);
	min_num = min(min(A, B), C);
	cout << max_num - min_num << endl;
}
