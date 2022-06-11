#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e0 + 5;

set<int> cut;
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int l, q;
	cin >> l >> q;
	cut.insert(0);
	cut.insert(l);
	while (q--){
		int c,x; cin >> c >> x;
		if (c == 1){
			cut.insert(x);
		}
		else{
			cout << *cut.lower_bound(x) - *--cut.lower_bound(x) << "\n";
		}
	}
	return 0;
}