#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
use a prefix sum array to compute the sum, then compare with k
is there an occurence of x in the range l,r?
frequency array, but storing the indices of the occurences
e.g. 
{1,5,6,1,5,1,2,56,1,3}
freq[1] = {1,4,6,9}; (one indexed)

binary search for the first occurence >= l

alternatively, use a binary search tree
*/

const int nax = 1e5 + 5;
int n,k,q,a[nax];
unordered_map<int,set<int>> freq;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		freq[a[i]].insert(i);
		a[i] += a[i-1];
	}
	while (q--){
		int A,B,X,Y;
		cin >> A >> B >> X >> Y;
		if (a[Y] - a[X-1] > k){
			auto lowa = freq[A].lower_bound(X);
			auto lowb = freq[B].lower_bound(X);
			if (lowa != freq[A].end() and lowb != freq[B].end()){
				if (*lowa <= Y and *lowb <= Y){
					cout << "Yes\n";
					continue;
				}
			}
		}
		cout << "No\n";
	}
	
	
	return 0;
}