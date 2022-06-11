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
weight: K
value: N
limit: M

dp[i][j] stores the max value using the first i cages and j minutes
transition dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight]+value)
*/
int dp[1005][1005];

int c, m, weight, value;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> c >> m;
	
	f2(1,c+1){
		cin >> value >> weight;
		ff2(1,m+1){
			dp[i][j] = dp[i-1][j];
			if (j-weight>=0) dp[i][j] = max(dp[i][j],dp[i-1][j-weight]+value);
		}
	}
	
	cout << dp[c][m] << endl;


	return 0;
}