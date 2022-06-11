#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SCAN(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;
ll n,w,a,b,dp[100005];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	SCAN(n); SCAN(w);
	for (int i = 0; i < n; ++i){
		SCAN(a); SCAN(b);
		for (int j = w; j >= a; --j){
			dp[j] = max(dp[j], dp[j-a] + b);
		}
	}
	cout << dp[w] << "\n";
	return 0;
}