#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	int n; cin >> n;
	vector<int> arr(2*n);
	vector<char> op(2*n);
	for (int i = 0; i < n; ++i){
		cin >> op[i] >> arr[i];
		arr[i+n] = arr[i];
		op[i+n] = op[i];
	}
	vector<vector<int>> a(2*n,vector<int>(2*n,INT_MAX)), b(2*n,vector<int>(2*n,INT_MIN));
	function<pair<int,int>(int,int)> solve = [&](int l, int r){
		if (l == r) return make_pair(arr[l],arr[l]);
		int& cura = a[l][r];
		int& curb = b[l][r];
		if (cura == INT_MAX){
			for (int i = l; i < r; ++i){
				auto [w,x] = solve(l,i);
				auto [y,z] = solve(i+1,r);
				if (op[i+1] == 't'){
					cura = min(cura, w + y);
					curb = max(curb, x + z);
				}
				else if (op[i+1] == 'x'){
					cura = min({cura, w * y, x * y, z * w, x * z});
					curb = max({curb, w * y, x * y, z * w, x * z});
				}
			}
			// cout << l << " " << r << " " << cura << " " << curb << "\n";
		}
		assert(cura != INT_MAX and curb != INT_MIN);
		return make_pair(cura,curb);
	};
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i){
		ans = max(ans, solve(i,i+n-1).second);
	}
	cout << ans << "\n";
	for (int i = 0; i < n; ++i){
		if (solve(i,i+n-1).second == ans){
			cout << i+1 << " ";
		}
	}
	cout << "\n";
	return 0;
}