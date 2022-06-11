#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 4e2 + 5;
int r,c,a[nax][nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; ++i){
		string s; cin >> s;
		for (int j = 1; j <= c; ++j){
			a[i][j] = s[j-1] == 'X';
			a[i][j] += a[i][j-1];
		}
	}
	int ans = 0;
	for (int left = 1; left <= c; ++left){
		for (int right = left; right <= c; ++right){
			int start = 1;
			for (int row = 1; row <= r; ++row){
				if (a[row][right] - a[row][left-1] == 0){
					// cout << left << " " << right << " " << start << " " << row << "\n";
					ans = max(ans, (right - left + 1 + row - start + 1) * 2);
				}
				else start = row + 1;
			}
		}
	}
	cout << ans - 1 << "\n";
	return 0;
}