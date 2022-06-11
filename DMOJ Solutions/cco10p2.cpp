#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
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
dp[node][D'] stores the minimum number of prunes to obtain (white - black) = D' = N+D. this way we can handle negative differences
base case at leaf:
	if the current node is white: dp[node][1+N] = 0
	if the current node is black: dp[node][-1+N] = 0
for every node:
	dp[node][0+N] = 1
because it takes 1 operation to prune this entire subtree obtaining a D value of 0

"each node has at most 2 children"
transition:
if we are not a leaf and we have at most 2 children, then we have 2 cases
1. if we have 1 child:
	for every possible D' (of the child's subtree):
		our new D' is current_node_colour + D' (for this subtree)
		if that is within the bounds:
			dp[node][newD'] = min(dp[node][newD'],dp[child][D']); // it takes 0 operations to not prune it
2. if we have 2 children:
	for every possible D'1 (of the first child's subtree):
		for every possible D'2 (of the second child's subtree):
			our new D' is current_node_colour + D'1 + D'2 - n (for this subtree) (dont shift it twice)
			if that is within the bounds:
				dp[node][newD'] = min(dp[node][newD'], dp[child1][D'1]+dp[child2][D'2])
			

answer is dp[root][D + N]
*/


const int nax = 305;
int colour[nax], dp[nax][2*nax], children[nax];
vi adj[nax];
int n, d;
int id, c, C;


void solve(int node){
	dp[node][n] = 1;
	if (children[node] == 0){
		dp[node][colour[node]+n] = 0;
		return;
	}
	if (children[node] == 1){
		solve(adj[node][0]);
		for (int D = 0; D <= 2*n; D++){
			int newD = colour[node] + D;
			if (0 <= newD && newD <= 2*n){
				dp[node][newD] = min(dp[node][newD], dp[adj[node][0]][D]);
			}
		}
		return;
	}
	if (children[node] == 2){
		solve(adj[node][0]);
		solve(adj[node][1]);
		for (int D1 = 0; D1 <= 2*n; D1++){
			for (int D2 = 0; D2 <= 2*n; D2++){
				int newD = colour[node] + D1 + D2 - n;
				if (0 <= newD && newD <= 2*n){
					dp[node][newD] = min(dp[node][newD], dp[adj[node][0]][D1] + dp[adj[node][1]][D2]);
				}
			}
		}
		return;
	}
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,d);
	f(n){
		in3(id,c,C);
		if(!c) c--;
		colour[id] = c;
		ff(C){
			int child; in(child);
			adj[id].pb(child);
		}
		children[id] = C;
	}
	mem(dp,infb);
	solve(0);
	
	out( ((dp[0][d+n]==inf) ? -1 : dp[0][d+n]) );
	
	return 0;
}




















//trailing lines ftw