#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, K;
	string S;
	cin >> N >> K;
	cin >> S;
	int count = 0;
	for(size_t i = 0; i < S.size();i++)
	{
		if (S[i] == '1') count++;
	}
	if (count % 2 == K % 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}