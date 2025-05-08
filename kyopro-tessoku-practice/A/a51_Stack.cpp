#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Q;
int Query[100009];
string x[100009];
stack<string> S;


int main()
{
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		cin >> Query[i];
		if (Query[i] == 1)
			cin >> x[i]; 
	}
	// クエリ処理
	for (int i = 1; i <= Q; i++)
	{
		if (Query[i] == 1) S.push(x[i]);
		if (Query[i] == 2) cout << S.top() << endl;
		if (Query[i] == 3) S.pop();
		
	}
	return 0;
}
