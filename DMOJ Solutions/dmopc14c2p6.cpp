#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e5 + 5;
int n,q,s[nax*2],ans[nax];
pair<int,int> m[nax];
struct query{
	int a,b,q,idx;
} queries[nax];

void update(int pos, int val){
	for (s[pos += nax] = val; pos /= 2;){
		s[pos] = s[pos*2] + s[pos*2+1];
	}
}

int sum(int l, int r){
	int res = 0;
	for (l += nax, r += nax; l < r; l /= 2, r /= 2){
		if (l % 2) res += s[l++];
		if (r % 2) res += s[--r];
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> m[i].first; m[i].second = i;
	}
	sort(m,m+n,greater<pair<int,int>>());
	int q; cin >> q;
	for (int i = 1; i <= q; ++i){
		int a,b,c; cin >> a >> b >> c;
		queries[i] = {a,b,c,i};
	}
	sort(queries+1,queries+1+q,[](query a, query b){
		return a.q > b.q;
	});
	int mptr = 0;
	for (int i = 1; i <= q; ++i){
		while (mptr < n and m[mptr].first >= queries[i].q){
			update(m[mptr].second,m[mptr].first);
			mptr++;
		}
		ans[queries[i].idx] = sum(queries[i].a, queries[i].b + 1);
	}
	for (int i = 1; i <= q; ++i){
		cout << ans[i] << "\n";
	}
	
	return 0;
}