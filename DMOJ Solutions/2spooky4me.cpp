#include <bits/stdc++.h>
using namespace std;


const int nax = 1e5 + 5;
pair<int,int> updates[nax*2];
int n, l, s, a, b, c;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> l >> s;
	for (int i = 0; i < n; ++i){
		cin >> a >> b >> c;
		updates[i] = {a,c};
		updates[n + i] = {b + 1,-c};
	}
	updates[2 * n] = {l + 1, 0};
	sort(updates, updates + 2 * n + 1);
	
	int ans = 0;
	
	int prev = 1, curspook = 0;
	for (int i = 0; i < 2 * n + 1; ++i){
		// cout << prev << " " << curspook << "\n";
		int pos, spook;
		tie(pos, spook) = updates[i];
		if (curspook < s){
			ans += (pos - 1 - prev + 1);
			// cout << (pos - 1 - prev + 1) << "\n";
		}
		prev = pos;
		curspook += spook;
	}
	cout << ans << "\n";
	

	return 0;
}