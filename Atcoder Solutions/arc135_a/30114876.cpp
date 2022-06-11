#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const ll mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*

*/

gp_hash_table<ll,ll> dp;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	ll x; cin >> x;
	function<ll(ll)> solve = [&](ll n){
		if (dp.find(n) != dp.end()) return dp[n];
		if (n <= 4) return n;
		return dp[n] = solve(n/2) * solve((n+1)/2) % mod;
	};
	out(solve(x));
	return 0;
}