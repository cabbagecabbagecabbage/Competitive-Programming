#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (long long i = 0; i < a; ++i)
#define ff(a) for (long long j = 0; j < a; ++j)
#define f2(a, b) for (long long i = a; i < b; ++i)
#define ff2(a, b) for (long long j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<long long> vi;
typedef pair<long long, long long> pii;

/*

*/

const long long nax = 1e0 + 5;

unordered_map<long long,long long> row, col;
long long n,m,k,a,b;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,m,k);
	f(k){
		in(a,b);
		row[a] ^= 1ll;
		col[b] ^= 1ll;
	}
	long long r = 0, c = 0, ans = 0;
	for (pair<long long,long long> k: row){
		r += k.second;
	}
	for (pair<long long,long long> k: col){
		c += k.second;
	}
	ans += min(r,c);
	ans += r - min(r,c);
	ans += c - min(r,c);
	out(ans);
	return 0;
}