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

long long dp[20005];
int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    int x,n;
    cin >> x >> n;
    vector<long long> coins;
    f(n){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    f(x+1){
        for (long long c: coins){
            dp[i+c] = min(dp[i+c],dp[i]+1);
        }
    }
    cout << dp[x] << endl;
	return 0;
}