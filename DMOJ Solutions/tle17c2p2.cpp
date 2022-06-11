#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e6 + 5;
int n,k,arr[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	while (k--){
		int u; cin >> u;
		arr[u] = 1;
	}
	for (int i = 1; i <= 1e6; ++i){
		arr[i] += arr[i-1];
	}
	cin >> n;
	while (n--){
		int f;
		cin >> f;
		cout << f - arr[f] << "\n";
	}
	return 0;
}