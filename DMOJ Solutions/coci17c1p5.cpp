#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <cstring>
#include <climits>
using namespace std;
#define int long long

/*

*/

const int nax = 2e5 + 5;
int n,q;
int s[nax*4];

void update(int v, int tl, int tr, int pos, int val){
	if (tl == tr){
		s[v] = val;
		return;
	}
	int mid = (tl + tr) / 2;
	if (pos <= mid) update(v*2, tl, mid, pos, val);
	else update(v*2+1, mid+1, tr, pos, val);
	s[v] = min(s[v*2],s[v*2+1]);
}

int query(int v, int tl, int tr, int ql, int qr, int y){
	int mid = (tl + tr) / 2;
	if (tr < ql || qr < tl) return LLONG_MAX;
	if (ql <= tl and tr <= qr){
		if (tl == tr) return tl;
		if (s[v*2] <= y){
			return query(v*2,tl,mid,ql,qr,y);
		}
		else if (s[v*2+1] <= y) return query(v*2+1,mid+1,tr,ql,qr,y);
		else return LLONG_MAX;
	}
	int ans = LLONG_MAX;
	if (s[v*2] <= y) ans = min(ans,query(v*2,tl,mid,ql,qr,y));
	if (s[v*2+1] <= y) ans = min(ans,query(v*2+1,mid+1,tr,ql,qr,y));
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < nax*4; ++i) s[i] = LLONG_MAX;
	cin >> n >> q;
	for (int i = 0; i < q; ++i){
		char op; int a,b;
		cin >> op >> a >> b;
		if (op == 'M'){
			//M X A
			update(1,1,n,b,a);
		}
		else{
			//D Y B
			if (b == n){
				cout << -1 << "\n";
				continue;
			}
			int ans = query(1,1,n,b,n,a);
			cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
		}
	}
	return 0;
}