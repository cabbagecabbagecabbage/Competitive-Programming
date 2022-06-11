#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e5 + 5;
int q,freq[nax], psa[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	//O(N)
	for (int i = 0; i < s.length(); ++i){
		//G -> 1
		//otherwise -> 0
		freq[i+1] = (s[i] == 'G');
	}
	//O(N)
	for (int i = 1; i <= s.length(); ++i){
		psa[i] = psa[i-1] + freq[i];
	}
	//O(Q)
	cin >> q;
	while (q--){
		int a,b; cin >> a >> b;
		++a; ++b;
		cout << psa[b] - psa[a-1] << "\n";
	}
	
	return 0;
}