#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") //RTE
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #include <ext/pb_ds/tree_policy.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
// #define int 					long long //MLE, TLE, CE
#define f(a) 					for (int i = 0; i < a; ++i)
#define ff(a) 					for (int j = 0; j < a; ++j)
#define f2(a, b) 				for (int i = a; i < b; ++i)
#define ff2(a, b) 				for (int j = a; j < b; ++j)
#define min(a, b) 				((a) < (b) ? (a) : (b))
#define max(a, b) 				((a) > (b) ? (a) : (b))
#define outs(a)					cout << a << " "
#define nl()					cout << "\n"
#define inf 					0x3f3f3f3f
#define llinf 					0x3f3f3f3f3f3f3f3f
#define eb 						emplace_back
#define mem(a, b)				memset(a, b, sizeof a)
#define	dt(a)					decltype(a)
#define fil(a, val) 			fill((RA<dt(a)>::type*)&a,(RA<dt(a)>::type*)((char*)&a+sizeof a),val)
template<typename T> 			struct RA {typedef T type;};
template<typename T, size_t sz> struct RA<T[sz]> {typedef typename RA<T>::type type;};
template<typename T> void in(T& x){cin>>x;}
template<typename T,typename... Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void out(const T& x,const Args&...args){outs(x),out(args...);}
int gcd(int a, int b)			{return (b == 0 ? a : gcd(b,a%b));}
int lcm(int a, int b)			{return a * b / (gcd(a,b));}
typedef vector<int> 			vi;
typedef pair<int, int> 			pii;
typedef vector<pair<int,int>> 	vpii;

////////////////////////////	END OF TEMPLATE	   ////////////////////////////


/*
backwards?
*/

const int nax = 4e5 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n,m,k,parent[nax],size[nax],removed[nax];
pii M[nax / 2];
vi adj[nax];
vi ans;
stack<int> unremove;

int Find(int node){
	return parent[node] = (node == parent[node] ? node : Find(parent[node]));
}

void Merge(int a, int b){
	a = Find(a); b = Find(b);
	if (size[a] > size[b]) swap(a,b);
	parent[a] = b;
	size[b] += size[a];
}


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,m);
	int numofcomp = n;
	f(n) parent[i] = i, size[i] = 1;
	f(m){
		in(M[i].first,M[i].second);
		adj[M[i].first].eb(M[i].second);
		adj[M[i].second].eb(M[i].first);
	}
	in(k);
	f(k){
		int a; in(a);
		removed[a] = 1;
		unremove.push(a);
		--numofcomp;
	}
	f(m){
		if (!removed[M[i].first] and !removed[M[i].second]){
			if (Find(M[i].first) != Find(M[i].second)){
				--numofcomp;
				Merge(M[i].first,M[i].second);
			}
		}
	}
	ans.eb(numofcomp);
	while (!unremove.empty()){
		int node = unremove.top(); unremove.pop();
		removed[node] = 0;
		++numofcomp;
		// out(node);
		for (int v: adj[node]){
			if (!removed[v] and Find(v) != Find(node)){
				--numofcomp;
				Merge(v,node);
			}
			// outs(v);
		}
		// nl();
		ans.eb(numofcomp);
	}
	for (int i = ans.size()-1; i >= 0; --i) out(ans[i]);
	
	
	
	return 0;
}