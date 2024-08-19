#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	if (S == "ACE" || S == "BDF" || S == "CEG" || S == "DFA" || S == "EGB" || S == "GBD" || S == "FAC")
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}