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
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int dp[105][105];

int n;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;int val;
	f(n){
		ff(i+1){
			cin >> val;
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]+val);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + val);
		}
	}
	int ans = 0;
	f(n){
		ans = max(ans,dp[n][i]);
	}

	cout << ans << endl;
	return 0;
}




















//trailing lines ftw