#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> arr(n+1),pre(n+1,-1),tree(2*n+5);
	auto update = [&](int pos, int val){
		for (tree[pos += n] = val; pos /= 2;){
			tree[pos] = (tree[pos*2] + tree[pos*2+1]) % mod;
		}
	};
	auto query = [&](int l, int r){
		int res = 0;
		for (l += n, r += n; l < r; l /= 2, r /= 2){
			if (l%2) res += tree[l++];
			if (r%2) res += tree[--r];
			res %= mod;
		}
		return res;
	};
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	vector<int> dp(n+1);
	update(0,1);
	for (int i = 1; i <= n; ++i){
		dp[i] = query(max(pre[arr[i]],0ll),i);
		if (pre[arr[i]] != -1) update(pre[arr[i]],0);
		update(i,dp[i]);
		pre[arr[i]] = i;
	}
	out(query(1,n+1));
	
	return 0;
}