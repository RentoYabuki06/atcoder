#include <iostream>

using namespace std;

int K, G, M;

int main()
{
	cin >> K >> G >> M;
	int c_grass = 0;
	int c_mag = 0;
	for (int i = 1; i <= K; i++)
	{
		if (c_grass == G) c_grass = 0;
		else if (c_mag == 0) c_mag = M;
		else
		{
			if (G - c_grass <= c_mag)
			{
				c_mag -= G - c_grass;
				c_grass = G;
			}
			else
			{
				c_grass += c_mag;
				c_mag = 0;
			}
		}
	}
	cout << c_grass << " " << c_mag << endl;
	return 0;
}