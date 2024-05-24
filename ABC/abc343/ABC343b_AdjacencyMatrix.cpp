#include <iostream>
#include <vector>	

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> vec[i];
			if (vec[i] == 1)
				cout << i+1 << " ";
		}
		cout << endl;
	}
	return 0;
}