#include <bits/stdc++.h>
using namespace std;

int last[9];

int32_t main(){
	memset(last,-0x3f,sizeof last);
	int n; cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i){
		int x,y,t; cin >> t >> x >> y;
		if (x <= 4){
			a += 100;
			if (t - last[x] <= 10){
				a += 50;
			}
			last[x] = t;
		}
		else {
			b += 100;
			if (t - last[x] <= 10){
				b += 50;
			}
			last[x] = t;
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}