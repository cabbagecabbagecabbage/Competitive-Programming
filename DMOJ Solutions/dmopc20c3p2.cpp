#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

const int nax = 21, maxx = 2e5+5;
int n, m, k, notes[maxx][nax];
gp_hash_table<int, int> exist[20];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m >> n >> k;
	int ans = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> notes[i][j];
			if (j) exist[j-1][notes[i][j-1]] = notes[i][j];
		}
	}
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n-1; j++)
			ans += (exist[j].find(notes[i][j]+k) != exist[j].end()) && (exist[j][notes[i][j]+k] == notes[i][j+1]+k);
	cout << ans << "\n";
	return 0;
}