#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1e9 + 7, inf = 0x3f3f3f3f3f3f3f3f;

/*
ff15
*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n+1),ps(n+1),pm(n+1);
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		ps[i] = ps[i-1] + a[i];
		pm[i] = max(pm[i-1],a[i]);
	}
	for (int i = 1; i <= n; ++i){
		ps[i] += ps[i-1];
	}
	for (int i = 1; i <= n; ++i){
		out(ps[i] + i * pm[i]);
	}
	return 0;
}