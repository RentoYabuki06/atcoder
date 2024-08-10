#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    reverse(A.begin(), A.end());
    
    vector<int> dp;
    
    for (int i = 0; i < N; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), A[i]);
        if (it == dp.end()) {
            dp.push_back(A[i]);
        } else {
            *it = A[i];
        }
    }
    
    cout << dp.size() << endl;
}
