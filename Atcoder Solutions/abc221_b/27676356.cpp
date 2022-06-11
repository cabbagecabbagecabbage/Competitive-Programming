// Problem: B - typo
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	string s,t;
	cin >> s >> t;
	if (s.length() != t.length()){
		cout << "No\n";
		return 0;
	}
	if (s == t){
		cout << "Yes\n";
		return 0;
	}
	for (int i = 0; i < s.length()-1; ++i){
		if (s[i] == t[i+1] && t[i] == s[i+1] && s.substr(0,i) == t.substr(0,i) && t.substr(i+2) == s.substr(i+2)){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}