#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #include <ext/pb_ds/tree_policy.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
#define int 					long long //MLE, TLE, CE
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
dp[i] max number of treats (so far) that can be had arriving at node i
since we are sorting distances we guarantee that any time we update, it is a valid path
dp[i] = max(dp[i], dp[j] + 1) (j being the other number in the pair)
*/


const int nax = 2e3 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n,x[nax],y[nax],dp[nax],tdp[nax];
pair<int,pii> pairs[nax*nax];

int dist(int a, int b){
	int h = x[a] - x[b];
	int v = y[a] - y[b];
	return h*h + v*v;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	f(n) in(x[i],y[i]);
	x[n] = y[n] = 0;
	int idx = 0;
	f(n){
		ff2(i+1,n){
			pairs[idx++] = {dist(i,j),{i,j}};
		}
	}
	f(n) pairs[idx++] = {dist(n,i),{n,i}};
	sort(pairs, pairs+idx);
	//process segments of same ones
	int start = 0;
	pairs[idx] = {-1,{-1,-1}};
	f(idx){
		if (pairs[i].first != pairs[i+1].first){
			//process
			ff2(start, i+1){
				int a = pairs[j].second.first, b = pairs[j].second.second;
				if (a != n){
					tdp[a] = max(tdp[a], dp[b] + 1);
					tdp[b] = max(tdp[b], dp[a] + 1);
				}
				else tdp[a] = max(tdp[a], dp[b]); // dont get candy at origin
			}
			f(n+1) dp[i] = tdp[i];
			start = i+1;
		}
	}
	out(dp[n]+1);
	return 0;
}