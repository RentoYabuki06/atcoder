#include <iostream>
#include <string>

using namespace std;

string S;

int main()
{
	cin >> S;
	int i = 0;
	while(S[i] == 'A') i++;
	while(S[i] == 'B') i++;
	while(S[i] == 'C') i++;
	if (i == S.size()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}