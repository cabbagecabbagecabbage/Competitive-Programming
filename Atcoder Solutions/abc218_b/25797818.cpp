#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e0 + 5;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; string s;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string ans = "";
	for (int i = 0; i < 26; ++i){
		int c; cin >> c;
		ans += alpha[c-1];
	}
	cout << ans << "\n";
}