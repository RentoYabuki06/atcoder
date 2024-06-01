#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int X[3009];
int Y[3009];
set<int> dots;

// 2点 (x1, y1) と (x2, y2) から作られる正方形の面積を計算する
int side_to_area(int x1, int y1, int x2, int y2) {
	int area = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return area;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i] >> Y[i];
        dots.insert(X[i] + 5000 * Y[i]);
    }
    int largest_area = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; i != j && j <= N; j++) 
        {
            int x_distance = X[i] - X[j];
            int y_distance = Y[i] - Y[j];
            int first_place = X[i] + 5000 * Y[i];
            int second_place = X[j] + 5000 * Y[j];
            int diff = y_distance - 5000 * x_distance;
			bool paternA = dots.count(first_place - diff) && dots.count(second_place - diff) && first_place >= diff && second_place >= diff;
			bool paternB = dots.count(first_place + diff) && dots.count(second_place + diff) && first_place <= diff && second_place <= diff;
            if(paternA || paternB)
            {
                int area = side_to_area(X[i], Y[i], X[j], Y[j]);
                largest_area = max(largest_area, area);
            }
        }
    }
    cout << largest_area << endl;
    return 0;
}
