#include <bits/stdc++.h>
using namespace std;

int prefix[1000000];

int main() {
	long n;
	cin >> n;
	prefix[0] = 0;
	for (long i=1; i<n+1; i++){
		int m;
		long p;
		scanf("%d",&m);
		p = m + prefix[i-1];
		prefix[i] = p;
		
	}
	int q;
	cin >> q;
	for (long i=0; i<q; i++){
		long a,b;
		scanf("%ld%ld",&a,&b);
		cout << prefix[b+1]-prefix[a] << endl;
	}

}