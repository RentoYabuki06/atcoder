#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> alpha(H);
	for (int i = 0; i < H ; i++)
	{
		string S;
		cin >> S;
		alpha.at(i) = S;
	}
	int len = alpha.at(0).size();
	for (int i = 0; i < len + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < H; i++)
	{
		cout << "#";
		cout << alpha.at(i);
		cout << "#" << endl;;
	}
	for (int i = 0; i < len + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
}