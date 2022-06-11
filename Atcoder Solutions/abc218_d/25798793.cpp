
// Problem: D - Rectangles
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define int long long
/*

*/

const int nax = 2e3 + 5;
int n;
unordered_map<int,unordered_map<int,int>> ep;
pair<int,int> points[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> points[i].first >> points[i].second;
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (points[i].first == points[j].first){
				if (points[i].second < points[j].second)
					ep[points[i].second][points[j].second]++;
				else
					ep[points[j].second][points[i].second]++;
			}
		}
	}
	int ans = 0;
	for (pair<int,unordered_map<int,int>> k: ep){
		for (pair<int,int> l: k.second){
			ans += l.second * (l.second-1) / 2;
		}
	}
	cout << ans << "\n";
	
	return 0;
}