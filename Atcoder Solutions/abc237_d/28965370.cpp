#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n; string s;
	cin >> n >> s;
	vector<int> l(n+1,-1), r(n+1,-1);
	for (int i = 1; i <= n; ++i){
		if (s[i-1] == 'L'){
			l[i] = l[i-1];
			r[i] = i-1;
			if (l[i-1] != -1) r[l[i-1]] = i;
			l[i-1] = i;
		}
		else {
			l[i] = i-1;
			r[i] = r[i-1];
			if (r[i-1] != -1) l[r[i-1]] = i;
			r[i-1] = i;
		}
	}
	int cur = -1;
	for (int i = 0; i <= n; ++i){
		if (l[i] == -1){
			cur = i;
			break;
		}
	}
	while (cur != -1){
		cout << cur << " ";
		cur = r[cur];
	}
	cout << "\n";		
	return 0;
}