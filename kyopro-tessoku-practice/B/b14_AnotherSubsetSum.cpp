#include <iostream>
#include <algorithm>

using namespace std;

int N, K, A[33], first[1000009], second[1000009];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	//前半の組み合わせ全列挙
	for (int i = 0; i < (1 << (N / 2)); i++)
	{
		int sum = 0;
		for (int j = 0; j <= N / 2; j++)
		{
			if ((i >> j) & 1) sum += A[j];
		}
		first[i] = sum;
	}
	//後半の組み合わせ全列挙
	for (int i = 0; i < (1 << N - (N / 2)); i++)
	{
		int sum = 0;
		for (int j = 0; j <= N - (N / 2); j++)
		{
			if ((i >> j) & 1) sum += A[j + N / 2];
		}
		second[i] = sum;
	}
	sort(first, first + (1 << N / 2));
	for (int i = 1; i <= (1 << N - (N / 2)); i++)
	{
		int L = 0;
		int R =(1 << N / 2) - 1;
		while (L <= R)
		{
			int mid = (L + R) / 2;
			if (second[i] + first[mid] < K) L = mid + 1;
			else if (second[i] + first[mid] == K)
			{
				cout << "Yes" << endl;
				return 0;
			}
			else R = mid - 1;
		}
	}
	cout << "No" << endl;
	return 0;
}
