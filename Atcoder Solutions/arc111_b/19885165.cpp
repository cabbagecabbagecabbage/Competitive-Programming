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

const int nax = 4e5 + 5;

vi adj[nax];
int n,a,b,vis[nax],appeared[nax];

int cnt = 0;
bool hascycle = false;
void dfs(int node, int prev){
	cnt++;
	vis[node] = 1;
	for (int x: adj[node]){
		if (x == prev) continue;
		if (vis[x]) hascycle = true;
		else dfs(x,node);
	}
}
	

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int ans = 0;
	in(n);
	f(n){
		in2(a,b);
		adj[a].eb(b);
		adj[b].eb(a);
		appeared[a] = 1;
		appeared[b] = 1;
	}
	f(400001){
		if (appeared[i]){
			if (!vis[i]){
				cnt = 0;
				hascycle = false;
				dfs(i,-1);
				if (hascycle) ans += cnt;
				else ans += cnt - 1;
			}
		}
	}
	out(ans);



	return 0;
}




















//trailing lines ftw