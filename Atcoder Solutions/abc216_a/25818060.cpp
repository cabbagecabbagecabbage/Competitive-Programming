
// Problem: A - Signed Difficulty
// Contest: AtCoder - AtCoder Beginner Contest 216
// URL: https://atcoder.jp/contests/abc216/tasks/abc216_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e0 + 5;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double dinput;
	cin >> dinput;
	int x = dinput / 1;
	dinput -= x;
	int input = dinput * 10;
	if (0 <= input and input <= 2){
		cout << x << "-\n";
	}
	else if (3 <= input and input <= 6){
		cout << x << "\n";
	}
	else if (7 <= input and input <= 9){
		cout << x << "+\n";
	}
	
	
	return 0;
}