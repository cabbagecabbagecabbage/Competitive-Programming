#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
number of subarrays with sum > 0
*/

const int nax = 3e5 + 5;
int arr[nax], s[nax*2];

void update(int pos, int val){
	for (s[pos += nax] += val; pos /= 2;){
		s[pos] = s[pos*2] + s[pos*2+1];
	}
}

int query(int l, int r){
	int res = 0;
	for (l += nax, r += nax; l < r; l /= 2, r /= 2){
		if (l%2) res += s[l++];
		if (r%2) res += s[--r];
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i){
		int a; cin >> a;
		arr[i] = (a == 1 ? 1 : -1);
	}
	int ans = 0, pre = 0;
	update(pre+n,1);
	for (int i = 1; i <= n; ++i){
		pre += arr[i];
		ans += query(0,pre+n);
		update(pre+n,1);
	}
	cout << ans << "\n";	
	return 0;
}