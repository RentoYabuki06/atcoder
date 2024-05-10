#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    vector<int> index(N);
    for (int i = 0; i < N; i++) {
        index[P[i] - 1] = i;
    }
    
    int min_diff = INT_MAX;
    for (int i = 0; i <= N - K; i++) {
        int max_index = index[i];
        int min_index = index[i];
        for (int j = i + 1; j < i + K; j++) {
            max_index = max(max_index, index[j]);
            min_index = min(min_index, index[j]);
			if (max_index - min_index >= min_diff)
				break;
        }
        min_diff = min(min_diff, max_index - min_index);
    }
    
    cout << min_diff << endl;
    
    return 0;
}