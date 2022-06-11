#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a;
#define in2(a,b) cin >> a >> b;
#define in3(a,b,c) cin >> a >> b >> c;
#define out(a) cout << a << endl;
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
int dp[100005][105];
int n,m,x,y,b,s;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	mem(dp,-inf);
	dp[0][0] = 0;
	f(n){
		in2(x,y);in2(b,s);
		ff(101){
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]-j*m);
			//try to sell balls until we have j left next month
			for (int cur = j+1; cur < min(101,j+y+1); cur++){
				dp[i+1][j] = max(dp[i+1][j],dp[i][cur]+(cur-j)*s-cur*m);
			}
		}
		
		for (int j=100; j >= 0; j--){
			//try to buy j balls for next month
			for (int cur = max(0,j-x); cur < j; cur++){
				dp[i+1][j] = max(dp[i+1][j],dp[i+1][cur]-(j-cur)*b);
				dp[i+1][j] = max(dp[i+1][j],dp[i][cur]-(j-cur)*b-cur*m);
			}
		}
	}
	out(dp[n][0]);

	return 0;
}