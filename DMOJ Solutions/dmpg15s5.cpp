#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") //RTE
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
#define	DT(a)					decltype(a)
#define fil(a, val) 			fill((RA<DT(a)>::type*)&a,(RA<DT(a)>::type*)((char*)&a+sizeof a),val)
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
going left to right by columns, maintain a set of pairs <hi,lo> indicating a range update of colour those cells in the interval. use diff array
*/

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int nax = 1e4 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n,m,diff[nax];
vi del[nax],add[nax];
pii itop[nax*10];
gp_hash_table<int,int> updates;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scan(n); scan(m);
	int id = 0;
	f(m){
		int x,y,w,h;
		scan(x); scan(y); scan(w); scan(h);
		add[x].push_back(++id);
		del[x+w].push_back(id);
		itop[id] = {y,y+h-1};
	}
	int ans = 0;
	int prea = 0;
	f(n){
		if (del[i].size() == 0 and add[i].size() == 0){
			ans += prea;
			continue;
		}
		for (int k: del[i]){
			updates.erase(k);
		}
		for (int k: add[i]){
			updates[k] = 0;
		}
		mem(diff,0);
		for (pii k: updates){
			diff[itop[k.first].first]++;
			diff[itop[k.first].second+1]--;
		}
		prea = 0;
		f(n){
			diff[i+1] += diff[i];
			if (diff[i] % 2) ++prea;
		}
		ans += prea;
	}
	out(ans);
	return 0;
}