#include <iostream>
#include <string>

using namespace std;

void open(string ans, int count, int rest);
void close(string ans, int count, int rest);


void open(string ans, int count, int rest){
	if (rest != 0){
		open(ans + '(', count + 1, rest - 1);
		close(ans + '(', count + 1, rest - 1);
	}

}

void close(string ans, int count, int rest){
	if (rest == 0 && count ==0){
		cout << ans << endl;
	}
	if (rest != 0 && count >0){
		open(ans + ')', count -1, rest - 1);
		close(ans + ')', count -1, rest - 1);
	}

}

int main()
{
	int N;
	cin >> N;
	open("", 0, N);
	return 0;
}