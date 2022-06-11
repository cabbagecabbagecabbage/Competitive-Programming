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

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n = ri();
	vi a = rv(2*n);
	vector<pii> b(2*n);
	for (int i = 0; i < 2*n; ++i){
		b[i] = {a[i],i+1};
	}
	sort(all(b));
	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans += b[i+n].first > b[i].first;
	}
	out(ans);
	for (int i = 0; i < n; ++i){
		out(b[i].second,b[i+n].second);
	}
	return 0;
}