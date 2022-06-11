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
repeatedly find the centroid? but that would be too easy

recrusively starting from some node:
	recalculate subtrees O(n)
	find centroid O(n)
	output centroid, take in Z
	if reached X then terminate
	find which subtree (rooted at centroid) contains Z O(n)
	remove centroid
	repeat same process with that neighbor of the centroid leading to Z
*/

signed main(){
	int n = ri();
	vector<vi> adj(n+1,vi());
	vi sub(n+1), removed(n+1);
	for (int i = 0; i < n-1; ++i){
		int u = ri(), v = ri();
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	function<int(int,int)> subtree = [&](int u, int p){
		sub[u] = 1;
		for (int v: adj[u]){
			if (v == p or removed[v]) continue;
			sub[u] += subtree(v,u);
		}
		return sub[u];
	};
	function<int(int,int,int)> centroid = [&](int u, int p, int siz){
		for (int v: adj[u]){
			if (v == p or removed[v]) continue;
			if (sub[v]*2 > siz) return centroid(v,u,siz);
		}
		return u;
	};
	function<bool(int,int,int)> find_sub = [&](int u, int p, int target){
		if (u == target) return true;
		for (int v: adj[u]){
			if (v == p or removed[v]) continue;
			if (find_sub(v,u,target)) return true;
		}
		return false;
	};
	function<void(int)> solve = [&](int u){
		int C = centroid(u, 0, subtree(u, 0));
		cout << C << "\n";
		int dest = ri();
		assert(dest != -1);
		if (dest == 0) return;
		for (int v: adj[C]){
			if (removed[v]) continue;
			if (find_sub(v,C,dest)){
				dest = v;
				break;
			}
		}
		removed[C] = 1;
		solve(dest);
	};
	solve(1);
	return 0;
}