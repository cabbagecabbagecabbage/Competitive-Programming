#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e6 + 5;
int n,k;
int chair[nax*2], student[nax*2];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; ++i){
		int a; cin >> a;
		chair[a] = chair[a+n] = true;
	}
	for (int i = 1; i <= k+1; ++i){
		int a; cin >> a;
		student[a] = student[a+n] = i;
	}
	stack<int> s;
	for (int i = 1; i <= 2*n; ++i){
		if (student[i] != 0){
			s.push(student[i]);
			student[i] = student[i+n*(i <= n ? 1 : -1)] = 0;
		}
		if (chair[i]){
			if (!s.empty()){
				s.pop();
				chair[i] = chair[i+n*(i <= n ? 1 : -1)] = false;
			}
		}
	}
	cout << s.top() << "\n";
	
	return 0;
}