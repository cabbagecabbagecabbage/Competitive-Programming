#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
#define f(a) for (long long i = 0; i < a; i++)
#define ff(a) for (long long j = 0; j < a; j++)
#define f2(a, b) for (long long i = a; i < b; i++)
#define ff2(a, b) for (long long j = a; j < b; j++)
#define fb(a) for (long long i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<long long> vi;
typedef pair<long long, long long> pii;


/*
ava pun's solution was used as reference

attach an edge from the person to the person they hate and also the other way. we want to find the maximum subset of nodes such that no 2 nodes share an edge

run dfs on each component to find cycle in the component (there is 1 cycle in each component)
run another dfs at the same time cuz the previous one had directed edges, marking all nodes in the component visited so we dont run the first dfs on the same component again

then for each component we run a recursive dfs dp similar to a tree (but we have cycle). we first root the tree at one of the nodes in the cycle. to keep track of whether we have traversed through the cycle and come back, we keep track of the starting node and whether it was taken. if the starting node was taken, and you are connected to it, and the current node should be taken, then the current case is invalid
*/
#define maxn 1000005
long long n;
long long dp[2][maxn][2], money[maxn], hate[maxn], visited[maxn], visited2[maxn], incycle[maxn];
vi adj[maxn];

long long findcycle(long long node){
	if (visited[node]) return node;
	visited[node] = 1;
	long long deepest = findcycle(hate[node]);
	if (deepest != -1) incycle[node] = 1;
	if (deepest == node){
		return -1; //terminate marking nodes as incycle now that we've come full circle
	}
	return deepest; //continue marking nodes as incycle
}

void traversecomponent(long long node){
	if (visited2[node]) return;
	visited2[node] = 1;
	for (long long x: adj[node]) traversecomponent(x);
	traversecomponent(hate[node]);
}

long long solve(long long start, long long tookstart, long long current, long long takecurrent){
	long long& cur = dp[tookstart][current][takecurrent];
	if (cur!=-1) return cur;
	//check validity
	for (long long x:adj[current]){
		if (x==start){
			if (tookstart && takecurrent) return cur = -inf;
		}
	}
	//continue solving
	cur = takecurrent ? money[current] : 0;
	for (long long x:adj[current]){
		if (x!=start){
			if (takecurrent) cur += solve(start, tookstart, x, 0);
			else cur += max(solve(start, tookstart, x, 1), solve(start, tookstart, x, 0));
		}
	}
	return cur;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f2(1,n+1){
		in2(money[i],hate[i]);
		adj[hate[i]].pb(i);
	}
	mem(dp,-1);
	f2(1,n+1){
		if (!visited2[i]){
			findcycle(i);
			traversecomponent(i);
		}
	}
	
	long long ans = 0;
	
	f2(1,n+1){
		if (incycle[i] && dp[0][i][0]==-1) ans += max(solve(i,0,i,0),solve(i,1,i,1));
	}
	
	out(ans);

	return 0;
}




















//trailing lines ftw