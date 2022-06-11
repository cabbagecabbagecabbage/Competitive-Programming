#include <bits/stdc++.h>
using namespace std;

int main() {
  int list[50];
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> list[i];
	}
	sort(list,list+n);

	for (int i=0; i<n; i++){
		cout << list[i] << endl;
	}
}