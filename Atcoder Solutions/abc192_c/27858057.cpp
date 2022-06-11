#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n,k; cin >> n >> k;
	int a = n;
	for (int i = 0; i < k; ++i){
		string num = to_string(a), num2 = num;
		sort(num.begin(),num.end());
		sort(num2.begin(),num2.end(),greater<char>());
		int a1 = stoi(num2), a2 = stoi(num);
		a = a1 - a2;
	}
	cout << a << "\n";
	return 0;
}