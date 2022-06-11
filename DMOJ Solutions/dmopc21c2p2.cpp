#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 3e2 + 5;
int n,q,idxof[nax],curperm[nax],qperm[nax],ansperm[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		curperm[i] = i;
		idxof[i] = i;
	}
	while (q--){
		// cout << "num" << "\n";
		// for (int i = 1; i <= n; ++i){
			// cout << curperm[i] << " ";
		// }
		// cout << "\n";
		// cout << "idx" << "\n";
		// for (int i = 1; i <= n; ++i){
			// cout << idxof[i] << " ";
		// }
		// cout << "\n";
		char op;
		cin >> op;
		if (op == 'B'){
			int x,y; cin >> x >> y;
			swap(curperm[x],curperm[y]);
			idxof[curperm[x]] = x;
			idxof[curperm[y]] = y;
		}
		else if (op == 'E'){
			int x,y; cin >> x >> y;
			swap(curperm[idxof[x]],curperm[idxof[y]]);
			swap(idxof[x],idxof[y]);
		}
		else{
			for (int i = 1; i <= n; ++i){
				int a; cin >> a;
				ansperm[idxof[i]] = a;
			}
			for (int i = 1; i <= n; ++i){
				cout << ansperm[i] << (i == n ? "" : " ");
			}
			cout << "\n";
		}
	}
	
	return 0;
}