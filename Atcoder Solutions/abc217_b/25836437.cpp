
// Problem: A - Lexicographic Order
// Contest: AtCoder - AtCoder Beginner Contest 217
// URL: https://atcoder.jp/contests/abc217/tasks/abc217_a
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
	vector<string> s = {"ABC","ARC","AHC","AGC"};
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (string st: s){
		if (st != s1 and st != s2 and st != s3){
			cout << st << "\n";
		}
	}
	
	
	return 0;
}