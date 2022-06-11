#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/cake
*/

const int nax = 5e3 + 5;
long long n,m,grid[nax][nax],k;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	while (k--){
		int a,b,c,d; cin >> a >> b >> c >> d;
		++grid[a][b];
		--grid[c+1][b];
		--grid[a][d+1];
		++grid[c+1][d+1];
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
		}
	}
	int q; cin >> q;
	while (q--){
		int a,b,c,d; cin >> a >> b >> c >> d;
		cout << grid[c][d] - grid[a-1][d] - grid[c][b-1] + grid[a-1][b-1] << "\n";
	}
	return 0;
}