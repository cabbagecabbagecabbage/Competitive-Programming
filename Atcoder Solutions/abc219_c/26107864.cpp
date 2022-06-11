#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e0 + 5;
unordered_map<char,int> indexof;
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string x; cin >> x;
	for (int i = 0; i < 26; ++i) indexof[x[i]] = i;
	vector<string> ss;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		ss.emplace_back(s);
	}
	sort(ss.begin(),ss.end(),[](string a, string b){
		for (int i = 0; i < min(a.length(),b.length()); ++i){
			if (a[i] == b[i]) continue;
			return indexof[a[i]] < indexof[b[i]];
		}
		return a.length() < b.length();
	});
	for (int i = 0; i < n; ++i){
		cout << ss[i] << "\n";
	}	
	return 0;
}