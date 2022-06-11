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
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (int j = 0; j < a; ++j)
#define f2(a, b) for (int i = a; i < b; ++i)
#define ff2(a, b) for (int j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


const int nax = 2e5 + 5;
int n,q,u,v,x,l,r,op,arr[nax];
int block[500][nax];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,q);
	const int sn = (int) sqrt(n + .0) + 1;
	f(n){
		in(arr[i]);
		for (int j = 1; j * j <= arr[i]; ++j){
			if (arr[i] % j == 0){
				block[i/sn][j]++;
				if (j * j != arr[i]) block[i/sn][arr[i]/j]++;
			}
		}
	}
	while (q--){
		in(op);
		if (op == 1){
			in(l,r,x);l--,r--;
			int ans = 0;
			while (l % sn && l <= r) ans += (arr[l++] % x == 0);
			while(l + sn <= r) {
	            ans += block[l/sn][x];
	            l += sn;
	        }
	        while (l <= r){
	        	ans += (arr[l++] % x == 0);
	        }
	        out(ans);
	    }
	    else {
	    	in(u,v); u--;
	    	for (int j = 1; j * j <= arr[u]; ++j){
				if (arr[u] % j == 0){
					block[u/sn][j]--;
					if (j * j != arr[u]) block[u/sn][arr[u]/j]--;
				}
			}
			arr[u] = v;
			for (int j = 1; j * j <= arr[u]; ++j){
				if (arr[u] % j == 0){
					block[u/sn][j]++;
					if (j * j != arr[u]) block[u/sn][arr[u]/j]++;
				}
			}
		}
	}
	return 0;
}