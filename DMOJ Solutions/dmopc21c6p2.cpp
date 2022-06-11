#include <bits/stdc++.h>
using namespace std;

/*
each interval stops right before a 1 or at the end

consider all contiguous intervals of 0

we can only take k of them
*/

int32_t main(){
	int n,k; cin >> n >> k;
	string s; cin >> s; s += '1';
	int ans = 0;
	vector<int> best;
	int last = s[0] == '0' ? 0 : -1;
	for (int i = 0; i < n+1; ++i){
		if (s[i] == '1'){
			if (last != -1) best.emplace_back(i - last);
			last = i+1;
		}
	}
	sort(best.begin(),best.end(),greater<int>());
	for (int i = 0; i < min(k,(int) best.size()); ++i){
		ans += best[i];
	}
	cout << ans << "\n";
	return 0;
}