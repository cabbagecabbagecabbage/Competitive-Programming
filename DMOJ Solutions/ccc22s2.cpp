#include <bits/stdc++.h>
using namespace std;

signed main(){
	unordered_map<string,unordered_map<string,bool>> yes,no;
	int x; cin >> x;
	for (int i = 0; i < x; ++i){
		string a,b; cin >> a >> b;
		yes[min(a,b)][max(a,b)] = false;
	}
	int y; cin >> y;
	for (int i = 0; i < y; ++i){
		string a,b; cin >> a >> b;
		no[min(a,b)][max(a,b)] = true;
	}
	int g; cin >> g;
	while (g--){
		vector<string> s(3);
		cin >> s[0] >> s[1] >> s[2];
		sort(s.begin(),s.end());
		if (yes.count(s[0]) and yes[s[0]].count(s[1])) yes[s[0]][s[1]] = true;
		if (yes.count(s[0]) and yes[s[0]].count(s[2])) yes[s[0]][s[2]] = true;
		if (yes.count(s[1]) and yes[s[1]].count(s[2])) yes[s[1]][s[2]] = true;
		
		if (no.count(s[0]) and no[s[0]].count(s[1])) no[s[0]][s[1]] = false;
		if (no.count(s[0]) and no[s[0]].count(s[2])) no[s[0]][s[2]] = false;
		if (no.count(s[1]) and no[s[1]].count(s[2])) no[s[1]][s[2]] = false;
	}
	int cnt = 0;
	for (auto [a,b]: yes){
		for (auto [c,d]: b){
			cnt += !d;
		}
	}
	for (auto [a,b]: no){
		for (auto [c,d]: b){
			cnt += !d;
		}
	}
	cout << cnt << "\n";
	return 0;
}