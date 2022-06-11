#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
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
int d,add,r;
string a,b;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in3(d,add,r);
	in2(a,b);
	int al = a.length();
	int bl = b.length();
	
	f(al+1){
		ff(bl+1){
			if (i==j && i==0) continue;
			if (i==0){
				dp[i][j] = dp[i][j-1]+add;
			}
			elif (j==0){
				dp[i][j] = dp[i-1][j]+d;
			}
			elif (a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1];
				continue;
			}
			else{
				dp[i][j] = min(min(dp[i-1][j-1]+r,dp[i-1][j]+d),dp[i][j-1]+add);
			}
		}
	}

	out(dp[al][bl]);

	return 0;
}




















//trailing lines ftw