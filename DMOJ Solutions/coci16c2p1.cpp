#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int ans = -1; string best;
	int s = 0;
	int n; cin >> n;
	while (n--){
		string name; int a, b;
		cin >> name >> a >> b;
		int t = 0;
		while (b >= a){
			++t;
			b -= a;
			b += 2;
		}
		if (t > ans){
			ans = t;
			best = name;
		}
		s += t;
	}
	cout << s << "\n";
	cout << best << "\n";
	
	return 0;
}