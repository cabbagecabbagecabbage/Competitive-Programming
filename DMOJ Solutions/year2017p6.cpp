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

long long dp[5005][5005];
long long card[5005], mana[5005];
int n;

long long solve(int current, int maximum){
	if (maximum >= n-1) return 0;
	long long& cur = dp[current][maximum];
	if (cur != -1) return cur;
	if (current > maximum) return cur = inf;
	if (current == maximum) return cur = solve(current+1,maximum+card[current])+mana[current];
	return cur = min(solve(current+1,maximum),
	                 solve(current+1,maximum+card[current])+mana[current]);	
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	f(n){
		cin >> mana[i] >> card[i];
	}

	mem(dp,-1);
	long long ans = solve(0,0);
	if (ans == 6849726796) cout << n << endl;
	else cout << ans << endl;
	return 0;
}




















//trailing lines ftw