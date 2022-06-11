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
when visitig a vertex
add 1 to every vertex that is an ancestor up to the true end. exclude the node itself
output diversion value thing (in order)

offline?

flatten the tree like so https://youtu.be/MOy4UDjN8DM?t=1963

keep track of the cnt when the node is entered and leaveed for each node

idea:
cnt		0	1	2	3	4	5	6	7	8	9	10	 11
node	3	2	1	-1	-2	5	4	-4	6	-6	-5	 -3		(negative indicating leaveing the node)

query for the divergence factor of node: query(entry[node]) - query(entry[node]-1)

use query result to do range update

shameless code copy paste from cp algo
*/

const long long mod = 1e9+7;
const long long nax = 400005;
long long bit[nax];
long long n;
long long parent[nax];
long long ans[nax];
vi adj[nax];
long long entry[nax],leave[nax];

void add(long long idx, long long val) {
    for (; idx <= 2 * n; idx += idx & -idx)
        bit[idx] = (bit[idx] + val) % mod;
}

void range_add(long long l, long long r, long long val) {
	//updates [l,r]
    add(l, val);
    add(r + 1, -val);
}

long long point_query(long long idx) {
	//returns sum
    long long ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret = (ret + bit[idx]) % mod;
    return ret;
}

long long actualquery(long long node){
	//the entire path's sum - the entire path with the node cancelled out sum = node's val
	//add 1 cuz we starting at 1 instead of 0
	return (point_query(entry[node]) - point_query(leave[node]) + 1 + mod) % mod;
}

long long cnt = 0;

void dfs(long long node){
	entry[node] = ++cnt;
	for (long long x: adj[node]) dfs(x);
	leave[node] = ++cnt;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	long long root = 0;
	f2(1,n+1){
		in(parent[i]);
		adj[parent[i]].pb(i); //parent to children for dfs
		if (parent[i]==0) root = i;
	}
	long long q;
	dfs(root);

	f2(1,n+1){
		in(q);
		ans[q] = actualquery(q);
		range_add(1,entry[parent[q]],ans[q]);
	}
	f2(1,n+1) cout << ans[i] << " ";
	out("");

	return 0;
}




















//trailing lines ftw