#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> key(m, vector<int>(n, 0));
    vector<string> r(m);
    
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            key[i][a - 1] = 1;
        }
        cin >> r[i];
    }

    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> tf(n);
        for (int j = 0; j < n; j++) {
            tf[j] = (i & (1 << j)) ? 1 : 0;
        }

        bool jud = true;
        for (int j = 0; j < m; j++) {
            int ck = 0;
            for (int p = 0; p < n; p++) {
                if (key[j][p] == 1 && tf[p] == 1) {
                    ck++;
                }
            }
            if ((ck >= k && r[j] == "x") || (ck < k && r[j] == "o")) {
                jud = false;
                break;
            }
        }
        if (jud) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
