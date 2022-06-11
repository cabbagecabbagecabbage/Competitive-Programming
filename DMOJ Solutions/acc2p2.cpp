#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define print(a) printf("%d\n", a);
#define print2(a,b) printf("%d %d\n", a, b);
#define n() printf("\n");

int n;
int adj[501][501];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	f(n) {
		bitset<501> temp;
		cin >> temp;
		ff(n) {
			if (i==n-j-1) adj[i][n-j-1] = 0;
			elif (temp[j]) adj[i][n - j - 1] = 1;
			else adj[i][n-j-1] = 1000000;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], (adj[i][k] + adj[k][j]));
			}
		}
	}
	int ans = 0;
	f(n) {
		for (int j=i+1; j < n; j++) {
			ans += (adj[i][j]==1000000 & adj[j][i]==1000000);
		}
	}
	cout << ans << "\n";
	return 0;
}