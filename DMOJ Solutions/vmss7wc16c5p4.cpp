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


int dp[100005];
int x,y,z;
int n;

int solve(int num){
	if (num < 0) return INT_MIN;
	if (dp[num] != -1) return dp[num];
	return dp[num] = max(solve(num-x),max(solve(num-y),solve(num-z)))+1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> x >> y >> z;
	mem(dp,-1);
	dp[0] = 0;
	cout << solve(n) << endl;


	return 0;
}




















//trailing lines ftw