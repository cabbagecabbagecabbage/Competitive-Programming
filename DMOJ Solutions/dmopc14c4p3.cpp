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

*/
int dp[1005][1005];
int grid[1005][1005];
int l,d;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> l >> d;
	
	f(d) ff(l) cin >> grid[i+1][j+1];
	mem(dp,0x3f);
	dp[1][0] = 0;
	f2(1,d+1){
		ff2(1,l+1){
			dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i][j+1]))+grid[i][j];
		}
		for (int j=l; j>0; j--){
			dp[i][j] = min(min(dp[i][j],dp[i-1][j]+grid[i][j]),min(dp[i][j-1]+grid[i][j],dp[i][j+1]+grid[i][j]));
		}
	}
	
	int x,y;
	cin >> x >> y;
	cout << dp[y+1][x+1] << endl;

	return 0;
}




















//trailing lines ftw