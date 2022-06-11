#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

/*
init tree with s[i]
range decre l...r
count negative numbers l...r
	store min and max
	if min < 0:
		if max < 0 return length of interval
		else go down left and right child
*/

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> s(n+1),tmin(4*n+5),tmax(4*n+5),lazy(4*n+5);
	function<void(int,int,int)> push = [&](int v, int left, int right){
		tmin[left] += lazy[v];
		tmax[left] += lazy[v];
		tmin[right] += lazy[v];
		tmax[right] += lazy[v];
		lazy[left] += lazy[v];
		lazy[right] += lazy[v];
		lazy[v] = 0;
	};
	function<void(int,int,int)> merge = [&](int v, int left, int right){
		tmin[v] = min(tmin[left],tmin[right]);
		tmax[v] = max(tmax[left],tmax[right]);
	};
	function<void(int,int,int)> build = [&](int v, int l, int r){
		if (l == r){
			tmin[v] = s[l];
			tmax[v] = s[l];
			return;
		}
		int m = (l + r) / 2, left = v*2, right = left + 1;
		build(left,l,m); build(right,m+1,r);
		merge(v,left,right);
	};
	function<void(int,int,int,int,int)> update = [&](int v, int l, int r, int ql, int qr){
		if (ql > r or qr < l) return;
		if (ql <= l and r <= qr){
			--tmin[v], --tmax[v], --lazy[v];
			return;
		}
		int m = (l + r) / 2, left = v*2, right = left + 1;
		push(v,left,right);
		update(left,l,m,ql,qr);
		update(right,m+1,r,ql,qr);
		merge(v,left,right);
	};
	function<int(int,int,int)> solve = [&](int v, int l, int r){
		if (tmax[v] < 0){
			tmax[v] = tmin[v] = n+1;
			lazy[v] = n+1;
			return r - l + 1;
		}
		if (tmin[v] < 0){
			int m = (l + r) / 2, left = v*2, right = left + 1;
			push(v,left,right);
			int res = solve(left,l,m) + solve(right,m+1,r);
			merge(v,left,right);
			return res;
		}
		return 0;
	};
	function<int(int,int,int,int,int)> query = [&](int v, int l, int r, int ql, int qr){
		if (ql > r or qr < l) return 0;
		int m = (l + r) / 2, left = v*2, right = left + 1;
		if (ql <= l and r <= qr){
			return solve(v,l,r);
		}
		push(v,left,right);
		int res = query(left,l,m,ql,qr) + query(right,m+1,r,ql,qr);
		merge(v,left,right);
		return res;
	};
	for (int i = 1; i <= n; ++i) cin >> s[i];
	build(1,1,n);
	int q; cin >> q;
	while (q--){
		int a,b; cin >> a >> b;
		update(1,1,n,a,b);
		cout << query(1,1,n,a,b) << "\n";
	}
	return 0;
}