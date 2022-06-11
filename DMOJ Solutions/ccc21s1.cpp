#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n;
double h[maxn], w[maxn];

int main(){
	cin >> n;
	double ans = 0;
	for (int i = 1; i <= n+1; ++i){
		cin >> h[i];
	}
	for (int i = 1; i <= n; ++i){
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i){
		ans += (h[i] + h[i+1]) * w[i];
	}
	cout << fixed << ans / 2 << "\n";
	return 0;
}