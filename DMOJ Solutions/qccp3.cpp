#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define int 				long long
#define f(a) 				for (int i = 0; i < a; ++i)
#define ff(a) 				for (int j = 0; j < a; ++j)
#define f2(a, b) 			for (int i = a; i < b; ++i)
#define ff2(a, b) 			for (int j = a; j < b; ++j)
#define fil(a, b) 			fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define mem(a, b)			memset(a, b, sizeof(a))
#define min(a, b) 			((a) < (b) ? (a) : (b))
#define max(a, b) 			((a) > (b) ? (a) : (b))
#define inf 				0x3f3f3f3f
#define llinf 				0x3f3f3f3f3f3f3f3f
#define eb 					emplace_back
typedef long long 			ll;
typedef vector<int> 		vi;
typedef pair<int, int> 		pii;

/*

*/

const int nax = 1e6 + 5, mod = 998244353;
int n,k,q,t;
int factorial[2*nax], inverse[2*nax];

long long binpow(long long num, long long pow) {
  long long ret = 1;
  while (pow) {
    if (pow % 2) ret = (ret * num) % mod;
    num = (num * num) % mod;
    pow /= 2;
  }
  return ret;
}

void precompute() {
  factorial[0] = 1;
  inverse[0] = 1;
  f2(1, 2*nax) {
    factorial[i] = (factorial[i - 1] * i) % mod;
    inverse[i] = binpow(factorial[i], mod - 2);
  }
}

long long nck(long long n, long long k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return (long long)((factorial[n] * inverse[k]) % mod * inverse[n - k]) % mod;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	precompute();
	in(t);
	while (t--){
		in(n,k,q);
		int spare = n - (k*q + q - 1);
		// if (q == 1){
			// cout << spare + 1 << "\n";
			// continue;
		// }
		// if (spare < 0){
			// cout << 0 << "\n";
			// continue;
		// }
		int space = 2 + q - 1;
		// C(n + k - 1, n)
		// n spares into k spaces
		// (n + k - 1)! / (n! * (k - 1)!)
		cout << nck(spare + space - 1, spare) << "\n";
	}

	return 0;
}