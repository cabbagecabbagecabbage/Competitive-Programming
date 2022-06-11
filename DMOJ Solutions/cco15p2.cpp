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


/*
dp[i][mask] = longest route that traverses from 0 through all vertices represented by mask ending at i 
*/
int dp[20][524288];
int matrix[20][20];
int n,m;

int solve(int node, int mask){
	if (dp[node][mask] != -1) return dp[node][mask];
	if (node==n-1) return 0; //reached end
	int ans = -inf; //if you cant reach a node with this path then set it to extremely short so that it wont be chosen
	f(n){
		if (matrix[node][i] && !(mask&(1<<i))){
			ans = max(ans,solve(i,mask|(1<<i))+matrix[node][i]);
		}
	}
	// cout << ans << endl;
	return dp[node][mask] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int s,d,l;
	f(m){
		cin >> s >> d >> l;
		matrix[s][d] = l;
	}

	mem(dp,-1);
	
	cout << solve(0,1) << endl;
	return 0;
}




















//trailing lines ftw