#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int rock = 0;
	int scissors = 0;
	int paper = 0;

    for (int i = 0; i < N; ++i)
	{
        char c = S[i];
        int new_rock = max(scissors, paper);
        int new_scissors = max(rock, paper);
        int new_paper = max(rock, scissors);

        if (c == 'R')
		{
            new_scissors = 0;
            new_paper++;       
        }
		else if (c == 'S')
		{
            new_paper = 0;
            new_rock++;
        }
		else if (c == 'P')
		{
            new_rock = 0;
            new_scissors++;
        }

        // 新しい値を元の変数に戻す
        rock = new_rock;
        scissors = new_scissors;
        paper = new_paper;
    }

    // rock, scissors, paper の中で最も大きい値を出力
    int ans = max(max(rock, scissors), paper);
    cout << ans << endl;

    return 0;
}
