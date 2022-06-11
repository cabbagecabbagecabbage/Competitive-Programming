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

int dp[1002][1002];
int n,m;
vector<int> vn,vm;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    int k;
    f(n){
    	cin >> k;
    	vn.push_back(k);
    }
    f(m){
    	cin >> k;
    	vm.push_back(k);
    }

    f2(1,n+1){
    	ff2(1,m+1){
    		if (vn[i-1]==vm[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
    		else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    	}
    }
    cout << dp[n][m] << "\n";
	return 0;
}