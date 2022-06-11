// #pragma GCC optimize("Ofast")
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
template<typename T> void scan(T& x){SCAN(x);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T,typename... Args> void scan(T& x,Args&...args){SCAN(x);scan(args...);}
template<typename T,typename... Args> void out(const T& x,const Args&...args){outs(x),out(args...);}

////////////////////////////	END OF TEMPLATE	   ////////////////////////////


/*

*/


const int nax = 1e5 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n,money,a[101],b[101],c[101],d[101],dp[nax];


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scan(n,money);
	f(n){
		scan(a[i],b[i],c[i],d[i]);
	}
	f(n){
		int price = (a[i] + c[i]), value = (b[i] + d[i]);
		for (int j = price; j <= money; ++j){
			dp[j] = max(dp[j],dp[j-price]+value);
		}
		for (int j = money; j >= a[i]; --j){
			dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
		}
		for (int j = money; j >= c[i]; --j){
			dp[j] = max(dp[j],dp[j-c[i]]+d[i]);
		}
	}
	out(dp[money]);
	return 0;
}