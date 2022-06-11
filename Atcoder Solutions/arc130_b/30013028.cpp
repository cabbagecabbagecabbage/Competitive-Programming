#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/
unordered_set<int> usedr, usedc;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int h,w,c,q; cin >> h >> w >> c >> q;
	vector<tuple<int,int,int>> a;
	for (int i = 0; i < q; ++i){
		int x,y,z; cin >> x >> y >> z; a.emplace_back(x,y,z);
	}
	reverse(a.begin(),a.end());
	vector<int> ans(c+1);
	int pr = 0, pc = 0;
	for (auto [t,n,m]: a){
		if (t == 1){
			if (usedr.count(n)) continue;
			usedr.insert(n);
			ans[m] += w - pc;
			pr += 1;
		}
		if (t == 2){
			if (usedc.count(n)) continue;
			usedc.insert(n);
			ans[m] += h - pr;
			pc += 1;
		}
	}
	for (int i = 1; i <= c; ++i) sp(ans[i]);
	return 0;
}