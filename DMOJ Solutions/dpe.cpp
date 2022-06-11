#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,w;
long long dp[100005];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> w;
    int weight,value;
    mem(dp,0x3f);
    dp[0] = 0;
    while(n--){
    	cin >> weight >> value;
    	for (int i=100000; i>=value; i--){
    		dp[i] = min(dp[i],dp[i-value]+weight);
    	}
    }
    for (int m = 100000; m>=0; m--){
    	if (dp[m]<=w){
    		cout << m << endl;
    		return 0;
    	}
    }
 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}