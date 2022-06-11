#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e5 + 5;
int n,m,x[maxn],y[maxn],k[maxn],d[maxn],val[maxn][21];

int32_t main(){
	cin >> n >> m;
	vector<pair<int,int>> slopes;
	for (int i = 1; i <= n; ++i){
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= m; ++i){
		cin >> k[i] >> d[i];
		bool ok = true;
		for (auto [a,b]: slopes){
			if (a * d[i] == b * k[i]){
				ok = false;
				break;
			}
		}
		if (ok){
			slopes.emplace_back(k[i],d[i]);
		}
	}
	unordered_map<int,int> freq;
	int ans = 0;
	for (auto [a,b]: slopes){
		for (int j = 1; j <= n; ++j){
			++freq[b * y[j] - a * x[j]];
		}
		for (auto [aa,bb]: freq){
			ans += bb * (bb-1) / 2;
		}
		freq.clear();
	}
	cout << ans << "\n";			
	return 0;
}