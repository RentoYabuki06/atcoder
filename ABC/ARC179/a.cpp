#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, K;
long long A[200009];
vector<long long> tmp;

int main()
{
	cin >> N >> K;
	long long total = 0;
	bool all_zero = true;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		total += A[i];
		tmp.push_back(A[i]);
		if (A[i] != 0) all_zero = false;
	}
	sort(tmp.begin(), tmp.end());
	if (K <= 0) reverse(tmp.begin(), tmp.end());
	if (all_zero)
	{
		cout << "Yes" << endl;
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << " ";
            cout << tmp[i];
        }
        cout << endl;
	}
	else if (K > 0 || (total >= K && K <= 0)) {
        cout << "Yes" << endl;
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << " ";
            cout << tmp[i];
        }
        cout << endl;
    }
	else {
        cout << "No" << endl;
    }

	return 0;
}