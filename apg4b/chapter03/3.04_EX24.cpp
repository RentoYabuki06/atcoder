#include <iostream>
#include <cstdio>
using namespace std;

struct Clock{
	int hour;
	int minute;
	int second;


	void	set(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}

	string	to_str(void)
	{
		string S;
		char hour01;
		char hour02;
		char min01;
		char min02;
		char sec01;
		char sec02;


		hour01 = "0123456789"[hour / 10];
		hour02 = "0123456789"[hour % 10];
		min01 = "0123456789"[minute / 10];
		min02 = "0123456789"[minute % 10];
		sec01 = "0123456789"[second / 10];
		sec02 = "0123456789"[second % 10];
		S += "\"";
		S += hour01;
		S += hour02;
		S += ":";
		S += min01;
		S += min02;
		S += ":";
		S += sec01;
		S += sec02;
		S += "\"";
		return S;
	}

	// メンバ関数 shift の定義を書く
	void	shift(int diff_second)
	{
		if (diff_second >= 0)
		{
			hour += diff_second / 3600;
			diff_second %= 3600;
			minute += diff_second / 60;
			diff_second %= 60;
			second += diff_second;
			while (second > 59)
			{
				minute += 1;
				second -= 60;
			}
			while (minute > 59)
			{
				hour += 1;
				minute -= 60;
			}
			while (hour > 23)
			{
				hour -= 24;
			}
		}
		else
		{
			diff_second = -diff_second;
			hour -= diff_second / 3600;
			diff_second = diff_second % 3600;
			minute -= diff_second / 60;
			diff_second = diff_second % 60;
			second -= diff_second;
			while (second < 0)
			{
				minute -= 1;
				second += 60;
			}
			while (minute < 0)
			{
				hour -= 1;
				minute += 60;
			}
			while (hour < 0)
			{
				hour += 24;
			}
		}
	}
};


// -------------------
// ここから先は変更しない
// -------------------

int main() {
  // 入力を受け取る
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock構造体のオブジェクトを宣言
  Clock clock;

  // set関数を呼び出して時刻を設定する
  clock.set(hour, minute, second);

  // 時刻を出力
  cout << clock.to_str() << endl;

  // 時計を進める(戻す)
  clock.shift(diff_second);

  // 変更後の時刻を出力
  cout << clock.to_str() << endl;
  return 0;
}
