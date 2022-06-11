#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 8e2 + 5;
int n,k,a[nax][nax],s[nax][nax];

bool hasmedian(int median){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			s[i][j] = (a[i][j] > median) + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}
	int target = k * k / 2; //needs to have k^2/2 greater than median
	for (int i = 1; i + k - 1 <= n; ++i){
		for (int j = 1; j + k - 1 <= n; ++j){
			int r = j + k - 1, d = i + k - 1;
			int cnt = s[d][r] - s[i-1][r] - s[d][j-1] + s[i-1][j-1];
			if (cnt <= target) return true; //lower median -> more numbers are greater
		}
	}
	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	int lo = 0, hi = 1e9, ans = -1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (hasmedian(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans	<< "\n";
	return 0;
}