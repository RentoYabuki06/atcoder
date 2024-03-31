#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> score(N);
	int sum = 0;;
	for (int i = 0; i < N; i++)
	{
		cin >> score.at(i);
		sum += score.at(i);
	}
	int ave = sum / N;
	for (int i = 0; i < N; i++)
	{
		if (ave > score.at(i)) cout << ave - score.at(i) << endl;
		else cout << score.at(i) - ave << endl;
	}
}