#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;

/*
dp[i] stores the maximum beauty so far if the last flower taken has height i
*/
long long dp[2 * 100000 + 5];
long long n;
long long height[2 * 100000 + 5];
long long beauty[2 * 100000 + 5];
long long tree[8 * 100000 + 5] = {};

long long query(int v, int l, int r, int ql, int qr) {
	if (ql > r || qr < l) {
		return 0;
	}
	elif (ql <= l && r <= qr) {
		return tree[v];
	}
	int m = (l + r) / 2;
	return max(query(v * 2, l, m, ql, qr), query(v * 2 + 1, m + 1, r, ql, qr));
}

void update(int v, int l, int r, int index, long long val) {
	if (l == r) {
		tree[v] = max(tree[v],val);
		return;
	}
	int m = (l + r) / 2;
	if (index > m) update(v * 2 + 1, m + 1, r, index, val);
	else update(v * 2, l, m, index, val);
	
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	f(n) cin >> height[i];
	f(n) cin >> beauty[i];
	f(n) {
		//we want to find the flower that is shorter than height[i] (height of current flower) with the maximum dp value (to continue that sequence with the current flower)
		long long tallest = query(1, 0, n - 1, 0, height[i] - 1);

		dp[height[i]] = max(dp[height[i]], tallest + beauty[i]);

		update(1, 0, n - 1, height[i], dp[height[i]]);
	}
	long long ans = 0;
	f(n + 1) ans = max(ans, dp[i]);
	cout << ans << endl;
	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}