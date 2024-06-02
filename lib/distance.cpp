#include <iostream>

using namespace std;

long double ft_distance(int x1, int y1, int x2, int y2)
{
	long double ans = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return ans;
}