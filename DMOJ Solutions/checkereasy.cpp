#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
/*

*/

const int nax = 3e3 + 5;
int n,m;
int arr[nax][nax];

int32_t main() {
	scan(m); scan(n);
	while (true){
		int r,c,x;
		scan(r); scan(c); scan(x);
		if (r == 0) break;
		arr[r][c] = x * (((r + c)&1)*2-1);
	}
	for (int i = 1; i <= m; ++i){
		for (int j = 1; j <= n; ++j){
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}
	while (true){
		int r1, c1, r2, c2;
		scan(r1); scan(c1); scan(r2); scan(c2);
		if (r1 == 0) break;
		cout << (arr[r2][c2] - arr[r1-1][c2] - arr[r2][c1-1] + arr[r1-1][c1-1]) * (((r1 + c1)&1)*2-1) << "\n";
	}
	return 0;
}