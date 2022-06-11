#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int ri(){int x; cin >> x; return x;}
vi rv(int l){vi v(l);generate(all(v),ri);return v;}
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}
#define var(x) cout<<#x<<": "<<x<<"\n"


const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*
subtree sizes, then math
*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n = ri();
	vector<vi> adj(n+1,vi());
	for (int i = 1; i < n; ++i){
		int u = ri(), v = ri();
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	vi sub(n+1), ans(n+1);
	function<int(int,int)> dfs = [&](int u, int p){
		sub[u] = 1;
		vi a;
		for (int v: adj[u]){
			if (v == p) continue;
			sub[u] += dfs(v,u);
			a.emplace_back(sub[v]);
		}
		a.emplace_back(n-sub[u]);
		int s = 0, ss = 0, sss = 0;
		for (int k: a) s += k, ss += k * k, sss += k * k * k;
		//no center: triplewise products sum * 6
		ans[u] += (s * s * s - 3 * s * ss + 2 * sss);
		//1 center: pairwise products sum * 6
		int pp = 0;
		for (int k: a) pp += (s - k) * k;
		ans[u] += pp * 3;
		//2 center: 3 * sum
		ans[u] += 3 * s; 		
		//3 center
		ans[u] += 1;
		return sub[u];
	}; dfs(1,0);
	for (int u = 1; u <= n; ++u){
		cout << ans[u] << " \n"[u == n];
	}
	return 0;
}