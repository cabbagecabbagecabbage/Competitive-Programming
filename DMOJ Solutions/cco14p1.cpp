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
dp[i][j] = the number of triangles that has its tip at grid[i][j]

idea: if 3 consecutive blocks are the tops of valid triangles of height h, then putting a block on the middle of these 3 will add h+1 triangles whose top is the new block on top
but if one of them had less, say h-3 triangles whose top is at that block, then putting a block on top would only add h-2 triangles whose top is the new block on top

the intuition is that putting 3 same sized triangles next to each other, then adding a single block on top will form a new triangle that is 1 taller than those 3, but notice that it also adds a triangle that is the same height as those three, and a triangle that is 1 shorter than those 3, and so on.

transition dp[i][j] = min(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])
*/
char grid[2005][2005];
int dp[2005][2005];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	f(n){
		ff(n){
			cin >> grid[i][j+1];
		}
	}
	int ans = 0;
	fb(n){
		ff2(1,n+1){
			if (grid[i][j]=='#'){
				dp[i][j] = min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1])) + 1;
				ans += dp[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}




















//trailing lines ftw