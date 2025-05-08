#include <iostream>

using namespace std;

int main()
{
	int N;
	long long A[100009], B[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
	long long truetrue = 0;
	long long truefalse = 0;
	long long falsetrue = 0;
	long long falsefalse = 0;
	for (int i = 1; i <= N; i++)
	{
		if ((A[i] >= 0 && B[i] >= 0) || (!(A[i] < 0 && B[i] < 0) && (A[i] + B[i]) > 0))
			truetrue += (A[i] + B[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		if ((A[i] >= 0 && B[i] <= 0) || (!(A[i] < 0 && B[i] > 0) && (A[i] - B[i] > 0)))
			truefalse += (A[i] - B[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		if ((A[i] <= 0 && B[i] >= 0) || (!(A[i] > 0 && B[i] < 0) && (B[i] - A[i]) > 0))
			falsetrue += (B[i] - A[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		if ((A[i] <= 0 && B[i] <= 0) || (!(A[i] > 0 && B[i] > 0) && (A[i] + B[i]) < 0))
			falsefalse -= (A[i] + B[i]);
	}
	long long ans = max(truetrue, falsefalse);
	long long tmp = max(truefalse, falsetrue);
	ans = max(ans, tmp);
	cout << ans << endl;
	return 0;
}