#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define SCAN(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;

/*
p[i] stores the number of strictly increasing subsequences ending at i (including a[i])
s[i] stores the number of structly decreasing subsequences starting at i (including a[i])

to calculate p[i]
	as we iterate forwards, maintain an array dp, where dp[i] stores the number of increasing subsequences with the last value = i
	dp[0] = 1 initiainty
	in each iteration
		p[i] = sum of aint dp[j] for aint 0 <= j < a[i]
		dp[a[i]] += p[i]

same logic with s[i]

segment tree for faster range sum
nvm use bit
*/

const int nax = 1e6 + 5, mod = 998244353;
int n, tree[nax], a[nax];
long long p[nax], s[nax];

// void update(int pos, int val){
	// pos += n+1;
	// for (tree[pos] = (tree[pos] + val) % mod; pos /= 2;){
		// tree[pos] = (tree[pos * 2] + tree[pos * 2 + 1]) % mod;
	// }
// }
// 
// int query(int l, int r){
	// int ra = 0, rb = 0;
	// for (l += n+1, r += n+1; l < r; l /= 2, r /= 2){
		// if (l%2) ra = (ra + tree[l++]) % mod;
		// if (r%2) rb = (rb + tree[--r]) % mod;
	// }
	// return (ra + rb) % mod;
// }

void update(int pos, int dif) { // a[pos] += dif
	for (; pos < n+1; pos |= pos + 1) tree[pos] = (tree[pos] + dif) % mod;
}
int query(int pos) { // sum of values in [0, pos)
	int res = 0;
	for (; pos > 0; pos &= pos - 1) res = (res + tree[pos-1]) % mod;
	return res;
}
	
int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int t; SCAN(t);
	while (t--){
		//input
		SCAN(n);
		for (int i = 0; i < n; ++i){
			SCAN(a[i]);
		}
		//forwards
		for (int i = 0; i < n+1; ++i) tree[i] = 0;
		update(0,1);
		for (int i = 0; i < n; ++i){
			p[i] = query(a[i]);
			update(a[i],p[i]);
		}
		//backwards and answer
		long long ans = 0;
		for (int i = 0; i < n+1; ++i) tree[i] = 0;
		update(0,1);
		for (int i = n-1; i >= 0; --i){
			s[i] = query(a[i]);
			update(a[i],s[i]);
			ans = (ans + p[i] * s[i] % mod) % mod;
		}
		cout << ans << "\n";
	}
	return 0;
}