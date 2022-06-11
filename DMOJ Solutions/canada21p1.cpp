// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") //RTE
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

*/


const int nax = 75e4 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int pr[nax], pw[nax];

void solve(){
	int n; string s;
	in(n,s);
	f2(1,n+1) pr[i] = pr[i-1] + (s[i-1] == 'R');
	f2(1,n+1) pw[i] = pw[i-1] + (s[i-1] == 'W');
	int prefixmin = pw[1]-pr[1], mx = 0; //prefixmin stores minimum (w's - r's) so far
	int l = 1, r = 1, preidx = 0;
	f2(1,n-1){
		if (pw[i+1] - pr[i+1] < prefixmin){
			prefixmin = pw[i+1] - pr[i+1];
			preidx = i;
		}
		if (pw[i+1] - pr[i+1] - prefixmin > mx){
			mx = pw[i+1] - pr[i+1] - prefixmin;
			l = preidx+1, r = i;
		}
	}
	// l,r inclusive and 0 indexed
	// out("data",l,r,mx);
	int ans = 0;
	ans += pw[l-1+1];
	ans += pw[n] - pw[r+1];
	ans += pr[r+1] - pr[l];
	out(ans);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; in(t);
	while (t--) solve();	
	return 0;
}