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
????
*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,t; cin >> n >> t;
	vector<pii> trees(t);
	for (int i = 0; i < t; ++i){
		cin >> trees[i].first >> trees[i].second;
	}
	trees.emplace_back(0,0);
	trees.emplace_back(n+1,n+1);
	sort(trees.begin(),trees.end());
	t = trees.size();
	int ans = 0;
	auto no = [&](int c){
		return !(1 <= c and c <= n);
	};
	//pick top and bottom
	for (int i = 0; i < t; ++i){
		for (int j = i+1; j < t; ++j){
			for (int k = 0; k < t; ++k){
				int len = trees[j].first - trees[i].first - 1;
				int y1 = trees[i].first + 1;
				int y2 = y1 + len - 1;
				int x1 = trees[k].second + 1;
				int x2 = x1 + len - 1;
				if (no(y1) or no(y2) or no(x1) or no(x2)) continue;
				bool ok = true;
				for (int l = 0; l < t; ++l){
					if (y1 <= trees[l].first and trees[l].first <= y2 and x1 <= trees[l].second and trees[l].second <= x2){
						ok = false;
						break;
					}
				}
				if (ok) ans = max(ans,len);
			}
		}
	}
	//pick left and right
	sort(trees.begin(),trees.end(),[](auto a, auto b){return a.second < b.second;});
	for (int i = 0; i < t; ++i){
		for (int j = i+1; j < t; ++j){
			for (int k = 0; k < t; ++k){
				int len = trees[j].second - trees[i].second - 1;
				int y1 = trees[k].first + 1;
				int y2 = y1 + len - 1;
				int x1 = trees[i].second + 1;
				int x2 = x1 + len - 1;
				if (no(y1) or no(y2) or no(x1) or no(x2)) continue;
				bool ok = true;
				for (int l = 0; l < t; ++l){
					if (y1 <= trees[l].first and trees[l].first <= y2 and x1 <= trees[l].second and trees[l].second <= x2){
						ok = false;
						break;
					}
				}
				if (ok) ans = max(ans,len);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}