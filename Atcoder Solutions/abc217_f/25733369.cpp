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
template<typename T,typename... Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T> void ui(T& x){SCAN(x);}
template<typename T,typename... Args> void ui(T& x,Args&...args){SCAN(x);ui(args...);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void out(const T& x,const Args&...args){outs(x),out(args...);}

////////////////////////////	END OF TEMPLATE	   ////////////////////////////


/*

*/


const int nax = 4e2 + 5, mod = 998244353; const double eps = 1e-9;
int dp[nax][nax],n,m;
bool good[nax][nax];
int fact[nax], invfact[nax];

int binpow(int base, int power){
	int ret = 1;
	while (power){
		if (power % 2) ret = ret * base % mod;
		base = base * base % mod;
		power /= 2;
	}
	return ret;
}

int choose(int n, int k){
	assert(n >= k);
	return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = invfact[0] = 1;
	f2(1,nax){
		fact[i] = (i * fact[i-1]) % mod;
		invfact[i] = binpow(fact[i], mod-2);
	}
	ui(n,m);
	f(m){
		int a,b; ui(a,b);
		good[a][b] = good[b][a] = true;
	}
	f2(1,2*n+2) dp[i][i-1] = 1;
	for (int length = 2; length <= 2*n; length += 2){
		for (int i = 1, j; (j = i + length - 1) <= 2*n; ++i){
			for (int k = i + 1; k <= j; k += 2){
				dp[i][j] += dp[i+1][k-1] * dp[k+1][j] % mod * choose(length / 2, (k - i + 1) / 2) % mod * good[i][k];
				dp[i][j] %= mod;
			}
		}
	}
	out(dp[1][2*n]);
	return 0;
}