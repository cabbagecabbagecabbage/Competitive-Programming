#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n; cin >> n;
	vector<bool> p(360);
	int angle = 0;
	p[angle] = true;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		angle = (angle + a) % 360;
		p[angle] = true;
	}
	int best = 0, last = -1;
	for (int i = 0; i < 360; ++i){
		if (p[i]){
			if (last != -1){
				best = max(best, i-last);
			}
			last = i+1;
		}
	}
	if (last != -1) best = max(best, 360-last);
	cout << best+1 << "\n";
	return 0;
}