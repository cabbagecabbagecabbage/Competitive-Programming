#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 2e5 + 5;
int n,k,a[nax],freq[nax];


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a,a+n);
	multiset<int> nums;
	int lp = 0, ans = 0;
	for (int rp = 0; rp < n; ++rp){
		nums.insert(a[rp]);
		while (*--nums.end() - *nums.begin() > k){
			nums.erase(nums.find(a[lp++]));
		}
		ans = max(ans, rp - lp + 1);
	}
	cout << ans << "\n";
	
	return 0;
}