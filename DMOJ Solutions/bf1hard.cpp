#include <bits/stdc++.h>
using namespace std;

int main() {
  long list[100001];
	long n;
	cin >> n;
	for (long i=0; i<n; i++){
		cin >> list[i];
	}
	sort(list,list+n);

	for (long i=0; i<n; i++){
		cout << list[i] << endl;
	}
	return 0;
}