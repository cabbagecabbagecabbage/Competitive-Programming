#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int, long long> tree; //node,depth

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	long long counter = 0;
	while (n--) {
		cin >> k;
		long long depth = 0;
		map<int, long long>::iterator a = tree.lower_bound(k); //first node greater than k
		if (a != tree.end()){ //if the element exists
			depth = max(depth, a->second+1);
		}
		if (a != tree.begin()){ //if there exists a node smaller
			a = prev(a); //go back
			depth = max(depth, a->second+1);
		} 
		//a->second+1, because 1 deeper than the max of those nodes
		tree[k] = depth;
		counter += depth;
		cout << counter << "\n";
	}
	return 0;
}