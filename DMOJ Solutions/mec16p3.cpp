#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e2 + 5;
int n, T, l[nax], t[nax][nax], x[nax][nax], dp[nax][nax];

int solve(int idx, int timeleft){
	if (idx == n) return 0;
	int& cur = dp[idx][timeleft];
	if (cur != -1) return cur;
	cur = max(cur, solve(idx+1, timeleft));
	int curexp = 0;
	for (int i = 0; i < l[idx]; ++i){
		curexp += x[idx][i];
		timeleft -= t[idx][i];
		if (timeleft < 0) break;
		cur = max(cur, curexp + solve(idx+1, timeleft));
	}
	return cur;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> T;
	for (int i = 0; i < n; ++i){
		cin >> l[i];
		for (int j = 0; j < l[i]; ++j){
			cin >> t[i][j] >> x[i][j];
		}
	}
	cout << solve(0,T) << "\n";	
	return 0;
}