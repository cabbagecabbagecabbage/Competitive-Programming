#include <bits/stdc++.h>
using namespace std;
#define int long long

int sqdist(int x1, int y1, int x2, int y2){
	int dy = y1 - y2;
	int dx = x1 - x2;
	return dy*dy + dx*dx;
}

signed main(){
	int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
	if (abs(x1-x2) > 6 or abs(y1-y2) > 6){
		cout << "No\n";
	}
	else {
		for (int i = min(x1,x2)-6; i <= max(x1,x2)+6; ++i){
			for (int j = min(y1,y2)-6; j <= max(y1,y2)+6; ++j){
				if (sqdist(i,j,x1,y1) == 5 and sqdist(i,j,x2,y2) == 5){
					cout << "Yes\n";
					return 0;
				}
			}
		}
		cout << "No\n";
	}
	return 0;
}