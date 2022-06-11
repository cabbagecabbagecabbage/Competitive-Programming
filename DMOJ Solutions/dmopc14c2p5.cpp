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
start at 1
flow down rivers until reaching a ded end
*/

double dp[1000005];
vi adj[1000005];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	int a, b;
	cin >> n >> m;
	f(m){
		cin >> a >> b;
		adj[--a].push_back(--b);
	}
	dp[0] = 1;
	f(n){
		int size = adj[i].size();
		if (size){
			double prob = dp[i] / size;
			for (int x: adj[i]) dp[x] += prob;
		}
	}
	cout << fixed << setprecision(12);
	f(n){
		int size = adj[i].size();
		if (!size){
			cout << dp[i] << endl;
		}
	}
	
	return 0;
}




















//trailing lines ftw