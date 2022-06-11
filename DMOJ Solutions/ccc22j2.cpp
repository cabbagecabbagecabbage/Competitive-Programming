#include <bits/stdc++.h>
using namespace std;

signed main(){
	bool isgold = true;
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		int a,b; cin >> a >> b;
		int points = a * 5 - b * 3;
		if (points > 40) ++cnt;
		else isgold = false;
	}
	cout << cnt;
	if (isgold) cout << "+";
	cout << "\n";
	return 0;
}