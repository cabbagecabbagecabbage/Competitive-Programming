#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
dp[i][j] stores the maximum score that can be obtained by using j balls on the first i pins

transition is dp[i][j] = max(dp[i-1][j],dp[i-w][j-1] + sum of pins from (i-w,i])

we can precalculate consecutive sums taken w at a time, rolling hash style sums[i] = sums[i-1]+arr[i]-arr[i-w]
*/

long long dp[30005][505];
long long n,k,w;
long long sums[30005]; //sums[i] stores the sum of (i-w,i] elements
long long arr[30005];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		mem(dp,0);
		mem(sums,0);
		mem(arr,0);
		cin >> n >> k >> w;
		f(n) cin >> arr[i+1];
		f2(1,n+1){
			sums[i] = sums[i-1]+arr[i];
			if (i-w>=0) sums[i] -= arr[i-w];
		}
		// f(n+1) cout << sums[i] << endl;
		
		ff2(1,k+1){
			f2(1,n+1){
				if (i-w < 0) dp[i][j] = sums[i];
				else dp[i][j] = max(dp[i-1][j],dp[i-w][j-1]+sums[i]);
			}
		}
		cout << dp[n][k] << endl;
	}

	

	return 0;
}