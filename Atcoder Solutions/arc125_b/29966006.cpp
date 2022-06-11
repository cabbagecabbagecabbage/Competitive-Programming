#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int ans = 0;
	for (int a = 1; a * a <= n; ++a){
		int limit = n / a;
		if (limit % 2 == a % 2) ++limit;
		ans += (limit - a + 1) / 2;
		ans %= mod;
	}
	out(ans);
	return 0;
}