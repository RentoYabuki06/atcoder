#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll sx, sy, tx, ty;

int main() {
    cin >> sx >> sy >> tx >> ty;
    ll height = abs(ty - sy);
    ll width = abs(tx - sx);
    ll ans = height; // 初期値として高さの差を設定
    
    ll tmp = width - height;
    
	if (tmp > 0)
	{
		// 幅の差が高さの差よりも大きい場合の調整
		if (tx > sx)
		{
			if (sy % 2 == 1 && sx % 2 == 0)tmp++;
			if (sy % 2 == 0 && sx % 2 == 1)tmp++;
		}
		else 
		{
			if (sy % 2 == 1 && sx % 2 == 1)tmp++;
			if (sy % 2 == 0 && sx % 2 == 0)tmp++;

		}
		if (tmp % 2 == 1) {
			if (tx > sx && sx % 2 == 1) tmp--;
			if (tx < sx && sx % 2 == 0) tmp--;
		}
		ans += (tmp / 2);
	}
    cout << ans << endl;
    return 0;
}
