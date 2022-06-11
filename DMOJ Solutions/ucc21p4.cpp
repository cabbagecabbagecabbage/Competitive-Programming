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

const int nax = 5e5 + 5;
int dist[nax], f[nax], a[nax], n;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	f[1] = 1;
	a[1] = 2;
	f2(2,n+1){
		f[i] = (f[i-1] + f[i-2]) % 2021;
		a[i] = (f[i] + 2021) % 2021 + (i + 50) % 50;
	}
	queue<int> q;
	mem(dist,inf);
	dist[1] = 0;
	q.push(1);
	while(!q.empty()){
		int node = q.front(); q.pop();
		if (dist[node+1] == llinf and node < n){
			dist[node+1] = dist[node] + 1;
			q.push(node+1);
		}
		if (dist[node-1] == llinf and node > 1){
			dist[node-1] = dist[node] + 1;
			q.push(node-1);
		}
		if (node - a[node] > 0 and dist[node - a[node]] == llinf){
			dist[node - a[node]] = dist[node] + 1;
			q.push(node - a[node]);
		}
		if (node + a[node] <= n and dist[node + a[node]] == llinf){
			dist[node + a[node]] = dist[node] + 1;
			q.push(node + a[node]);
		}
	}
	out(dist[n]);
	return 0;
}