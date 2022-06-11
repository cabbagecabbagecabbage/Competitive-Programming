#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e3 + 5;
int n;
string s[nax], t[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> s[i] >> t[i];
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (s[i] == s[j] and t[i] == t[j]){
				cout << "Yes" << "\n";
				return 0;
			}
		}
	}
	cout << "No" << "\n";
	
	return 0;
}