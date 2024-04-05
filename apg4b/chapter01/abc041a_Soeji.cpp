#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int i;
	cin >> s >> i;

	cout << s.at(i - 1) << endl;
	return 0;
}