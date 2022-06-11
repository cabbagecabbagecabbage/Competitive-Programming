#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e5 + 5;
int n,m,s[nax*2];

void update(int pos, int val){
	for (s[pos += nax] = val; pos /= 2;){
		s[pos] = min(s[pos*2],s[pos*2+1]);
	}
}

int query(int l, int r){
	int res = INT_MAX;
	for (l += nax, r += nax; l < r; l /= 2, r /= 2){
		if (l%2) res = min(res,s[l++]);
		if (r%2) res = min(res,s[--r]);
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> s[nax+i];
	}
	for (int i = nax-1; i > 0; --i){
		s[i] = min(s[i*2],s[i*2+1]);
	}
	while (m--){
		char op; cin >> op;
		if (op == 'M'){
			int i,x; cin >> i >> x;
			update(i,x);
		}
		else{
			int l,r; cin >> l >> r;
			cout << query(l,r+1) << "\n";
		}
	}	
	return 0;
}