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

*/

const int nax = 60 + 5;

long long dp[nax][2]; // dp[i][0] stores the number of tuples that achieve false with length i+1
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	dp[0][1] = 1;
	dp[0][0] = 1;
	f2(1,n+1){
		in(s);
		if (s[0] == 'A'){
			// and
			dp[i][1] = dp[i-1][1]; //we want cur to be true -> can only add a true
			dp[i][0] = (2 * dp[i-1][0] + dp[i-1][1]); //we want cur to be false -> add true or false to false, or add true to false
		}
		else{
			// or
			dp[i][1] = dp[i-1][0] + 2*dp[i-1][1]; //we want cur to be true -> add true to false, add true or false to true
			dp[i][0] = dp[i-1][0]; //we want cur to be false -> add false to false
		}
	}
	out(dp[n][1]);

	return 0;
}




















//trailing lines ftw