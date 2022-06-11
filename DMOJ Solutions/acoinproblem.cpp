#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
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

struct Query{
	int index,first,amount;
	Query(int i, int f, int a){
		index = i;
		first = f;
		amount = a;
	}
	bool operator < (const Query &other) const {
		return first>other.first; //reverse it bc prioqueue in c++ has the greatest on top
	}
};

int n,v;
int coins[2005];
int dp[10005];
int ans[100005];
priority_queue<Query> q;


/*
dp[j] stores the minimum amount of coins needed to make j dollars (with the first i coins but we dont store previous rows)

transition: min(dp[j],dp[j-value[i]]+1))
*/

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> v;
	f(n){
		cin >> coins[i+1];
	}
	
	int amount,first;
	f(v){
		cin >> amount >> first;
		q.push(Query(i,first,amount));
	}

	mem(dp,0x3f);
	dp[0] = 0;

	f2(1,n+1){
		ff(10001){
			if (j-coins[i]>-1) dp[j] = min(dp[j],dp[j-coins[i]]+1);
			//otherwise stay the same
			// cout << dp[j] << " ";
		}
		// cout << endl;
		while (!q.empty() && q.top().first==i){
			ans[q.top().index] = dp[q.top().amount];
			q.pop();
		}
	}

	f(v){
		if (ans[i]==0x3f3f3f3f) cout << -1 << endl;
		else cout << ans[i] << endl;
	}

 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}