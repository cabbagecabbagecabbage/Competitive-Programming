#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int ri(){int x; cin >> x; return x;}
vi rv(int l){vi v(l);generate(all(v),ri);return v;}
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*
every other column has the same sum
make sure there are no contradictions

type 1 - 1 missing info
type 2 - 2 missing info
determine the possible sums:
	max sum: smallest type 1 + M
	min sum: largest type 1 + 1

for every fixed sum, there is 1 way for type 1 to obtain the sum
all the type 2's are the same
how many ways?

a + b = k
(1 <= a,b <= M)

case 1: k - 1 <= m
	(1,k-1) -> (k-1,1)
	k-1 arrangements

case 2: k - 1 > m
	(m,k-m) -> (k-m,m)
	2m-k+1 arrangements unless k > 2m, which has 0 (but this wont happen)


mod
*/

int m;

int bp(int base, int power){
	int ret = 1;
	while (power){
		if (power%2){
			ret *= base;
			ret %= mod;
		}
		base = base * base % mod;
		power /= 2;
	}
	return ret;
}

int solve(vi &a, vi &b){
	int n = a.size();
	int fixed = -1;
	for (int i = 0; i < n; ++i){
		if (a[i] and b[i]){
			if (fixed != -1 and (a[i] + b[i] != fixed)){
				return 0;
			}
			fixed = a[i] + b[i];
		}
	}
	// out(fixed);
	if (fixed != -1){
		int ans = 1;
		for (int i = 0; i < n; ++i){
			if (a[i] == 0 and b[i] == 0){
				if (fixed-1 > m){
					ans *= (2*m-fixed+1);
					ans %= mod;
				}
				else if (fixed-1 <= m){
					ans *= (fixed-1);
					ans %= mod;
				}
			}
			else if (a[i] == 0 or b[i] == 0){
				if (a[i] == 0 and b[i] > 0)	swap(a[i],b[i]);
				if (a[i] + m < fixed or a[i] + 1 > fixed){
					return 0;
				}
			}
		}
		return ans;
	}
	else {
		//no fixed sum
		int type2 = 0;
		int lo = 1+1, hi = m+m;
		for (int i = 0; i < n; ++i){
			if (a[i] == 0 and b[i] == 0) type2++;
			else if (a[i] == 0 or b[i] == 0){
				if (a[i] < b[i]) swap(a[i],b[i]);
				lo = max(lo,a[i]+1);
				hi = min(hi,a[i]+m);
			}
		}
		assert(lo != INT_MIN and hi != INT_MAX);
		// out(lo,hi,type2);
		int ans = 0;
		for (int i = lo; i <= hi; ++i){
			// assert(i-lo < 10000000);
			if (i-1 > m){
				ans += bp(2*m-i+1,type2);
				ans %= mod;
			}
			else if (fixed-1 <= m){
				ans += bp(i-1,type2);
				ans %= mod;
			}
		}
		return ans;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n = ri();
	m = ri();
	vi a = rv(n), b = rv(n);
	vi even1, even2, odd1, odd2;
	for (int i = 0; i < n; i += 2){
		even1.emplace_back(a[i]);
		even2.emplace_back(b[i]);
	}
	for (int i = 1; i < n; i += 2){
		odd1.emplace_back(a[i]);
		odd2.emplace_back(b[i]);
	}
	out(solve(even1,even2)*solve(odd1,odd2)%mod);
	return 0;
}