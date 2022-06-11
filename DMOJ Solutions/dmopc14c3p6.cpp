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
limit is t
customers is n

dp[i][j] is the maximum profit made with the first i customers in j minutes

transition
dp[i][j] = max(dp[i-1][j-p1]+v1,dp[i-1][j-p2]+v2,dp[i-1][j-p1]+v3)
*/

long long pre[10005], cur[10005];

int n;
int t;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> t;
	int p1,v1,p2,v2,p3,v3;
	f(n){
		cin >> p1 >> v1 >> p2 >> v2 >> p3 >> v3;
		ff(t+1){
			if (j-p1>=0) cur[j] = max(cur[j],pre[j-p1]+v1);
			if (j-p2>=0) cur[j] = max(cur[j],pre[j-p2]+v2);
			if (j-p3>=0) cur[j] = max(cur[j],pre[j-p3]+v3);
		}
		f(t+1) pre[i] = cur[i];
	}
	
	cout << cur[t] << endl;

	return 0;
}




















//trailing lines ftw