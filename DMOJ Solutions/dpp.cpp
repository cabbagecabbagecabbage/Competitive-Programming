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

long long dp[100005][2]; //0->black, 1->white
vector<int> graph[100005];
long long mod = 1000000007;

void dfs(int node, int parent){
	dp[node][0] = dp[node][1] = 1;
	for (int i:graph[node]){
		if (i!=parent){
			dfs(i,node);
			dp[node][0] *= (dp[i][1])%mod;
			dp[node][0] %= mod;
			dp[node][1] *= ((dp[i][0]+dp[i][1]))%mod;
			dp[node][1] %= mod;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    int n, a, b;
    cin >> n;
    f(n-1){
    	cin >> a >> b;
    	a--;
    	b--;
    	graph[a].push_back(b);
    	graph[b].push_back(a);
    }

    dfs(0,-1);

    cout << (dp[0][0]+dp[0][1]) % mod << "\n";

	return 0;
}