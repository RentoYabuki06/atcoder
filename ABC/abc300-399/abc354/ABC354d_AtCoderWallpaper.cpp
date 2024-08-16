#include <iostream>

using namespace std;

long long A, B, C, D;

// 原点を左下、(a, b)を右上とした長方形の中の黒い面積を求める関数
long long ft_area(long long a, long long b)
{
	long long ra = a % 4;	// x 軸方向は4の倍数で繰り返される
	long long rb = b % 2;	// y 軸方向は2の倍数で繰り返される
	// 繰り返し部分の面積を足す
	a -= ra;
	b -= rb;
	long long res = a * b;
	// 繰り返し部分からはみ出た部分を足す(黒面積の2倍した値を足すことに注意)
	// 縦方向にははみ出ても1マスだけ(y軸方向は2の倍数で繰り返されるので)
	if (rb == 1) res += a;
	// 横方向にははみ出ても3マスだけ(y軸方向は4の倍数で繰り返されるので)
	if (ra >= 1)
	{
		res += b * 3 / 2;
		if (rb) res += 2;
	}
	if (ra >= 2)
	{
		res += b * 3 / 2;
		if (rb) res += 1;
	}
	if (ra >= 3) res += b / 2;
	return res;
}

int main()
{
	cin >> A >> B >> C >> D;
	// 第一象限へ移動
	A += 1e9;
	B += 1e9;
	C += 1e9;
	D += 1e9;
	// 解を求める。ft_area(A, B)が重複して轢かれるので、最後に足すことに注意
	long long ans = ft_area(C, D) - ft_area(A, D) - ft_area(C, B) + ft_area(A, B);
	cout << ans << endl;
}