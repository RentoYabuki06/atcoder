#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

int N;
int X[9];
int Y[9];

long double ft_distance(int x1, int y1, int x2, int y2)
{
	long double ans = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	vector<int> vec(N);
	iota(vec.begin(), vec.end(), 0); // 0からN-1までの整数で初期化

	long double total_distance = 0;
	unsigned long long perm_count = 0;

	do {
		long double current_distance = 0;
		for (int i = 0; i < N - 1; i++) {
			int cur_place = vec[i]; 
			int next_place = vec[i + 1];
			current_distance += ft_distance(X[cur_place], Y[cur_place], X[next_place], Y[next_place]);
		}
		total_distance += current_distance;
		perm_count++;
	} while (next_permutation(vec.begin(), vec.end()));

	long double ans = total_distance / perm_count;
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
