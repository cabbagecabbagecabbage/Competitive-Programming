#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e5 + 5;
int n,s,d[nax];

set<pair<int,int>> apple[100];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> d[i];
	while (s--){
		int stand, flavour; cin >> stand >> flavour;
		apple[flavour].insert({d[stand],stand});
	}
	int q; cin >> q;
	while (q--){
		char op; cin >> op;
		if (op == 'A'){
			int x,k; cin >> x >> k;
			assert(0 <= k and k < 100);
			apple[k].insert({d[x],x});
		}
		else if (op == 'S'){
			int x,k; cin >> x >> k;
			assert(0 <= k and k < 100);
			auto it = apple[k].find({d[x],x});
			if (it != apple[k].end()) apple[k].erase(it);
		}
		else if (op == 'E'){
			int x,k; cin >> x >> k;
			for (int i = 0; i < 100; ++i){
				auto it = apple[i].find({d[x],x});
				if (it != apple[i].end()) apple[i].erase(it);
			}
			d[x] = k;
		}
		else if (op == 'Q'){
			int k; cin >> k;
			if (k < 0 or k >= 100){
				cout << -1 << "\n";
				continue;
			}
			assert(0 <= k and k < 100);
			auto it = apple[k].begin();
			if (it != apple[k].end()) cout << (*it).second << "\n";
			else cout << -1 << "\n";
		}
	}
	
	return 0;
}