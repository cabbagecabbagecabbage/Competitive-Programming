#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
#define f(a) for (ll i = 0; i < a; i++)
#define ff(a) for (ll j = 0; j < a; j++)
#define f2(a, b) for (ll i = a; i < b; i++)
#define ff2(a, b) for (ll j = a; j < b; j++)
#define fb(a) for (ll i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
let the accusations and defenses be edges from one node to another
create another node 0 that connects to every node that does not have a parent to make sure every node get traversed

dp[node][i][j] stores the number of role assignments possible in the subtree rooted at the node; i indicating the number of were wolves and j indicating whether the current node is werewolf or civilian

transition:
for the current (parent) node:
1. 	if the parent is a citizen, then its children can be both citizen and werewolf. 
	dp[node][werewolf][1] += dp[node][werewolf][1] * (dp[child][werewolf][1] + dp[child][werewolf][0])
	where the number of werewold of each child doesnt exceed the number of werewolves in the node

2.	if the parent is a werewolf, then it depends on what kind of connection it is: accuse or defend
		if parent accuses child, then the child cannot be a werewolf.
		dp[node][werewolf][0] += dp[node][werewolf][0] * dp[node][werewolf][1]
		
		if the parent defends child, then the child node is definitely a werewolf
		dp[node][werewolf][0] += dp[node][werewolf][0] * dp[node][werewolf][0]
*/
const ll nax = 205, mod = 1e9+7;
ll n,w,m;
vi adj[nax][2]; //	0: accuse	1: defend
ll a,b;
ll dp[nax][nax][2];
int hasparent[nax];
char op;

//	0 -> werewolf 	1 -> civilian
void solve(int parent){
	dp[parent][0][1] = 1;
	dp[parent][1][0] = 1;
	// cout << "node " << parent << endl;
	//accuse children
	for (int child: adj[parent][0]){
		solve(child);
		for (int pwolf = w; pwolf >= 0; pwolf--){
			long long temp0 = 0, temp1 = 0;
			for (int cwolf = 0; cwolf <= pwolf; cwolf++){
				temp1 += dp[parent][pwolf-cwolf][1] * (dp[child][cwolf][0] + dp[child][cwolf][1]) % mod;
				temp0 += dp[parent][pwolf-cwolf][0] * (dp[child][cwolf][1]) % mod;
				temp1 %= mod;
				temp0 %= mod;
			}
			// cout << temp1 << " " << temp0 << endl;
			dp[parent][pwolf][0] = temp0;
			dp[parent][pwolf][1] = temp1;
		}
	}
	
	//defend children
	for (int child: adj[parent][1]){
		solve(child);
		for (int pwolf = w; pwolf >= 0; pwolf--){
			long long temp0 = 0, temp1 = 0;
			for (int cwolf = 0; cwolf <= pwolf; cwolf++){
				temp1 += dp[parent][pwolf-cwolf][1] * (dp[child][cwolf][0] + dp[child][cwolf][1]) % mod;
				temp0 += dp[parent][pwolf-cwolf][0] * (dp[child][cwolf][0]) % mod;
				temp1 %= mod;
				temp0 %= mod;
			}
			// cout << temp1 << " " << temp0 << endl;
			dp[parent][pwolf][0] = temp0;
			dp[parent][pwolf][1] = temp1;
		}
	}
}

int main() {
	// ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in3(n,w,m);
	f(m){
		in3(op,a,b);
		hasparent[b] = 1;
		if (op=='A') adj[a][0].pb(b);
		else adj[a][1].pb(b);
	}
	f2(1,n+1){
		if (!hasparent[i]) adj[0][0].pb(i); // accuse/defend doesnt actually matter
	}
	//we want all the node's possibilities so we choose when node 0 is citizen
	solve(0);
	
	out(dp[0][w][1]);

	return 0;
}




















//trailing lines ftw