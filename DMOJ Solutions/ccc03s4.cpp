#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	string cur = "";
	int ans = 0;
	for (int i = 0; i < s.length(); ++i){
		cur += s[i];
		string t = cur;
		reverse(t.begin(),t.end());
		vector<int> pi(i+2);
		int maxpi = 0;
		for (int j = 1; j < t.length(); ++j){
			int k = pi[j-1];
			while (k > 0 and t[j] != t[k]) k = pi[k-1];
			k += t[j] == t[k];
			pi[j] = k;
			maxpi = max(maxpi, pi[j]);
		}
		ans += i+1-maxpi;
	}
	cout << ans+1 << "\n";
}

int32_t main(){
	int n; cin >> n;
	while (n--) solve();
	return 0;
}