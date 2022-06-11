#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int ri(){int x; cin >> x; return x;}
void rv(vector<int>& v){generate(all(v),ri);}
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n = ri(), k = ri();
	int logk = ceil(log2(k))+2;
	vector<vi> p(n+1, vi(logk));
	vi a(n+1);
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		p[a[i]][0] = i;
	}
	// for (int i = 1; i <= n; ++i){
		// p[i][0] = a[a[i]];
		// out(a[i],a[a[i]]);
	// }
	for (int j = 1; j < logk; ++j){
		for (int i = 1; i <= n; ++i){
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
	for (int i = 1; i <= n; ++i){
		int ans = a[i];
		for (int j = logk-1; j >= 0; --j){
			if (k & (1ll << j)){
				ans = p[ans][j];
			}
		}
		sp(ans);
	}
	return 0;
}