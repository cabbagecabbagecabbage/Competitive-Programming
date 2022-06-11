#include <bits/stdc++.h>
using namespace std;

/*
problem: find the closest cut to the left and right of the mark (assuming 0 and L are cuts)
if we had an array or vector that stored the cuts in sorted order, we can binary search
how do we support updates?
	.insert O(length of vector that stores the cuts)
	
binary search trees
set<>
insert - O(logn)
lower_bound - O(logn)
	lower_bound(x)
	returns an iterator that points to the minimum element greater than or equal than x
	else return .end()
upper_bound - O(logn)
	lower_bound(x)
	returns an iterator that points to the minimum element strictly greater than x
	else return .end()


*/

const int nax = 1e0 + 5;
int l,q;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> q;
	set<int> cuts = {0,l};
	//O(QlogQ)
	//q <= 2*10^5
	while (q--){
		//O(Q)
		int c,x; cin >> c >> x;
		if (c == 1){
			//O(logQ)
			cuts.insert(x);
		}
		else{
			//O(logQ)
			cout << *cuts.lower_bound(x) - *--cuts.lower_bound(x) << "\n";
		}
	}
	
	return 0;
}