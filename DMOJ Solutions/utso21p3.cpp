#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;

/*
dp[i] stores the number of possible partitions of the first i elements
transititon
if current element >= prefix max:
	can new group
	iterate over all i < current and add on
else:
	dp[i] = dp[i-1]
	
*/

const int nax = 1e5 + 5;
const int mod = 1e9 + 7;
ll arr[nax],n,dp[nax];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f2(1,n+1) in(arr[i]);
	ll m = 0;
	dp[0] = 1;
	f2(1,n+1){
		if (arr[i] >= m){
			m = arr[i];
			ff(i){
				dp[i] += dp[j];
				dp[i] %= mod;
			}
		}
		else dp[i] = dp[i-1];
	}
	out(dp[n]);
	


	return 0;
}




















//trailing lines ftw