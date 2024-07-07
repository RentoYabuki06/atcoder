#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

ll a,b,c,d,e,f,g,h,i,j,k,l;
ll A[109];

int main()
{
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
	if (d <= g || j <= a) 
	{
		cout << "No" << endl;
		return 0; 
	}
	if (e <= h || k <= b) 
	{
		cout << "No" << endl;
		return 0; 
	}
	if (f <= i || l <= c) 
	{
		cout << "No" << endl;
		return 0; 
	}
	cout << "Yes" << endl;
	return 0; 
}
