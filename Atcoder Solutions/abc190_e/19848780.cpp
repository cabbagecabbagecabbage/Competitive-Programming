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

const int nax = 1e5 + 5;

int n,m,k,a,b,c;
int dist[18][nax];
vi want;
int dp[18][(1 << 18)];
vi adj[nax];

void bfs(int gemidx){
	int start = want[gemidx];
	dist[gemidx][start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()){
		int node = q.front(); q.pop();
		for (int x: adj[node]){
			if (dist[gemidx][x] > dist[gemidx][node] + 1){
				dist[gemidx][x] = dist[gemidx][node] + 1;
				q.push(x);
			}
		}
	}
}

int solve(int last, int mask){
	int& cur = dp[last][mask];
	if (mask == (1 << k) - 1) return 0;
	if (cur != -1) return cur;
	cur = inf;
	f(k){
		if (!(mask & (1 << i))){
			cur = min(cur,solve(i,mask^(1 << i)) + dist[last][want[i]]);
		}
	}
	return cur;
}
	
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	mem(dist,infb);
	in2(n,m);
	f(m){
		in2(a,b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	in(k);
	f(k){
		in(c);
		want.pb(c);
		bfs(i);
	}
	int ans = inf;
	mem(dp,-1);
	f(k){
		ans = min(ans,1+solve(i,(1 << i)));
	}
	out((ans == inf ? -1 : ans));

	return 0;
}




















//trailing lines ftw