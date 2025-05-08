#include <iostream>
#include <stack>
#include <string>

using namespace std;

string S;
stack<int> brackets;

int main()
{
	cin >> S;
	for (size_t i = 0; i < S.size(); i++)
	{
		if (S[i] == '(')
			brackets.push(i);
		else
		{
			cout << brackets.top() + 1 << " " << i + 1 << endl;
			brackets.pop();
		}
	}
	return 0;
}