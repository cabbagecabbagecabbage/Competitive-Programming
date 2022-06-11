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
	int n = ri();
	vector<vector<int>> g(n,vector<int>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> g[i][j];
		}
	}
	vi rows, cols;
	for (int i = 0; i < n; ++i){
		int cnt = 0;
		for (int j = 0; j < n; ++j){
			cnt += g[i][j];
		}
		if (g[i][0] == 0){
			rows.emplace_back(i+1);
			for (int j = 0; j < n; ++j){
				g[i][j] = !g[i][j];
			}
		}
	}
	for (int j = 0; j < n; ++j){
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			cnt += g[i][j];
		}
		if (g[0][j] == 1){
			cols.emplace_back(j+1);
			for (int i = 0; i < n; ++i){
				g[i][j] = !g[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (g[i][j]){
				out(-1);
				return 0;
			}
		}
	}
	out(rows.size() + cols.size());
	for (auto i: rows) out('R',i);
	for (auto i: cols) out('C',i);
	return 0;
}