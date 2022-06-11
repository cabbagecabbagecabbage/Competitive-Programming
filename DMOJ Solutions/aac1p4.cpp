#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
vector<int> occ[100005];
int size[100005];
int n,q,l,r,x,arr[nax];

int bsearch(int num, int l, int r){
	int lo = 0, hi = size[num] - 1;
	int ans = INT_MAX;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (occ[num][mid] == l){
			return occ[num][mid];
		}
		if (occ[num][mid] > l){
			hi = mid - 1;
			ans = occ[num][mid];
		}
		else{
			lo = mid + 1;
		}
	}
	if (ans > r){
		return -1;
	}
	return ans;
}
			

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> arr[i];
		occ[arr[i]].emplace_back(i);
		size[arr[i]]++;
	}
	while (q--){
		cin >> l >> r >> x;
		bool no = true;
		for (int a = 1; a * a < x; ++a){
			if (x % a == 0){
				int b = x / a;
				
				int firsta = bsearch(a,l,r);
				if (firsta == -1) continue;
				int firstb = bsearch(b,l,r);
				if (firstb == -1) continue;
				
				no = false;
				cout << "YES" << "\n";
				break;
			}
		}
		if (no) cout << "NO" << "\n";
	}
	return 0;
}