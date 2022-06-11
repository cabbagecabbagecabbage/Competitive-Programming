#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
int d,f,t,w[maxn],ans[maxn];
vector<int> adj[maxn];
bool canthear[maxn];
bitset<maxn> barks[maxn];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> d;
	for (int i = 1; i <= d; ++i) cin >> w[i];
	cin >> f;
	for (int i = 0; i < f; ++i){
		int x,y; cin >> x >> y;
		adj[x].emplace_back(y);
	}
	barks[0][1] = 1;
	cin >> t;
	vector<int> processed;
	for (int i = 0; i <= t; ++i){
		int dog = barks[i]._Find_first();
		while (dog < (int) barks[i].size()){
			processed.emplace_back(dog);
			for (int nextdog: adj[dog]){
				if (!canthear[nextdog] and i + w[nextdog] <= t){
					barks[i+w[nextdog]][nextdog] = 1;
					canthear[nextdog] = true;
				}
			}
			++ans[dog];
			dog = barks[i]._Find_next(dog);
		}
		for (int m: processed) canthear[m] = false;
		processed.clear();
	}
	for (int i = 1; i <= d; ++i) cout << ans[i] << "\n";
	return 0;
}