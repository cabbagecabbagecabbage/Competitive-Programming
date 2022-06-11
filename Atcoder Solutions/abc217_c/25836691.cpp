
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

const int nax = 2e5 + 5;
int ans[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int p; cin >> p;
		ans[--p] = i+1;
	}
	for (int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	
	return 0;
}