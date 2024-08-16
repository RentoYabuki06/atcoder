#include <iostream>
#include <string>


using namespace std;

int main()
{
	string s;
	cin >> s;
	int i = s.size() - 1;
	while (i >= 0)
	{
		if (s[i] == '.') break;
		i -= 1;
	}
	cout << s.substr(i + 1) << endl;
	return 0;
}