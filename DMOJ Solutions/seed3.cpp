#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e5 + 5;
int m,n,j,diff[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> j;
	for (int i = 0; i < j; ++i){
		int a,b,c;
		cin >> a >> b >> c;
		diff[a] += c;
		diff[b+1] -= c;
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i){
		diff[i] += diff[i-1];
		if (diff[i] < n){
			++ans;
		}
	}
	cout << ans << "\n";
	
	return 0;
}