#include <bits/stdc++.h>
using namespace std;

/*
query 2 - output the length of the piece of timber that has mark x
what is the first cut to the right of mark x?
what is the first cut to the left of mark x?
output the difference between the positions of the cuts

if we had a sorted array/vector of the positions of the cuts, we can binary search for both positions
how can we insert a number into our sorted array/vector?
vector<int> v;
v.insert(pos,number); //O(n) wrt the number of elements that is to the right of the position

cuts.insert(x)

we can use a ordered set instead
set<int> cuts = {0,l};
cuts.lower_bound(x) -> iterator that points to the first cut to the right of x
prev(cuts.lower_bound(x)) -> itterator that points to the first cut to the left of x
*/

const int nax = 1e0 + 5;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int l,q; cin >> l >> q;
	set<int> cuts = {0,l}; //stores the positions of the cuts in sorted order
	//O(QlogQ)
	//2*10^5 * (log(2) + 5log(10))
	//c++ 10^8
	while (q--){
		// O(Q)
		int c,x; cin >> c >> x;
		if (c == 1){
			cuts.insert(x); //O(logQ)
		}
		else if (c == 2){
			//O(logQ)
			auto right = cuts.lower_bound(x); // iterator pointing to the first cut to the right
			auto left = prev(right); //iterator pointing to the first cut to the left
			cout << *right - *left << "\n";
		}
	}
	return 0;
}