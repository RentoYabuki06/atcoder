#include <iostream>
#include <map>
#include <string>

using namespace std;

int Q;
int query[100009];
int score[100009];
string name[100009];
map<string, int> student;

int main()
{
	// 入力
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> query[i];
		if (query[i] == 1)
			cin >> name[i] >> score[i];
		else
			cin >> name[i];
	}
	// mapに代入
	for (int i = 0; i < Q; i++)
	{
		if (query[i] == 1)
			student[name[i]] = score[i];
		else
			cout << student[name[i]] << endl;
	}
	return 0;
}

