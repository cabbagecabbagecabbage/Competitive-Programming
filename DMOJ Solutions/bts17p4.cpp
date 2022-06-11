// Problem: Back To School '17: Wet Mud
// Contest: DMOJ
// URL: https://dmoj.ca/problem/bts17p4
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// #pragma GCC optimize("Ofast")
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
#define SCAN(x) 				while((x=getchar())<'0');char _;for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
int gcd(int a, int b)			{return (b == 0 ? a : gcd(b,a%b));}
int lcm(int a, int b)			{return a * b / (gcd(a,b));}
typedef vector<int> 			vi;
typedef pair<int, int> 			pii;
typedef vector<pair<int,int>> 	vpii;
template<typename T> 			struct RA {typedef T type;};
template<typename T, size_t sz> struct RA<T[sz]> {typedef typename RA<T>::type type;};
template<typename T> void in(T& x){cin>>x;}
template<typename T,typename... Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T> void ui(T& x){SCAN(x);}
template<typename T,typename... Args> void ui(T& x,Args&...args){SCAN(x);ui(args...);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void out(const T& x,const Args&...args){outs(x),out(args...);}

////////////////////////////	END OF TEMPLATE	   ////////////////////////////


/*
dp[i] stores the min time to get to spot i
dp[0] = 0, dp[n+1] -> desired
sort in order of position
for each patch of mud
	find the min time between [curpos-jump,curpos-1]. dp[i] = max(mintime, curtime)

*/

struct Tree {
	typedef int T;
	static constexpr T unit = inf;
	T fn(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = fn(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = fn(ra, s[b++]);
			if (e % 2) rb = fn(s[--e], rb);
		}
		return fn(ra, rb);
	}
};

const int nax = 1e6 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n,m,j,dp[nax];
pii q[nax];
Tree t(nax);

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ui(n,m,j);
	f(m){
		ui(q[i].first,q[i].second);
	}
	sort(q, q + m);
	q[m] = {n+1,0};
	t.update(0,0);
	f(m+1){
		t.update(q[i].first,max(t.query(q[i].first-j,q[i].first),q[i].second));
		// out(q[i].first,q[i].second,t.query(q[i].first,q[i].first+1));
	}
	int ans = t.query(n+1,n+2);
	out(ans == inf ? -1 : ans);
	return 0;
}