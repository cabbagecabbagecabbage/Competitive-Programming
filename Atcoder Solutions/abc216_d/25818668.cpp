// Problem: D - Pair of Balls
// Contest: AtCoder - AtCoder Beginner Contest 216
// URL: https://atcoder.jp/contests/abc216/tasks/abc216_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 2e5 + 5;
int n,m;
vector<int> b[nax];
deque<int> deques[nax];
set<pair<int,int>> s;
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int k; cin >> k;
		for (int j = 0; j < k; ++j){
			int a; cin >> a;
			deques[i].push_front(a);
		}
		b[deques[i].back()].emplace_back(i);
	}
	for (int colour = 1; colour <= n; ++colour){
		s.insert({b[colour].size(),colour});
	}
	int paired = n;
	while (paired){
		pair<int,int> best = *--s.end();
		if (best.first < 2){
			cout << "No" << "\n";
			return 0;
		}
		s.erase(best);
		int d1 = b[best.second][0], d2 = b[best.second][1];
		deques[d1].pop_back();
		if (deques[d1].size()){
			s.erase({b[deques[d1].back()].size(), deques[d1].back()});
			b[deques[d1].back()].emplace_back(d1);
			s.insert({b[deques[d1].back()].size(), deques[d1].back()});
		}
		deques[d2].pop_back();
		if (deques[d2].size()){
			s.erase({b[deques[d2].back()].size(), deques[d2].back()});
			b[deques[d2].back()].emplace_back(d2);
			s.insert({b[deques[d2].back()].size(), deques[d2].back()});
		}
		b[best.second].clear();
		paired--;
	}
	cout << "Yes" << "\n";
	return 0;
}