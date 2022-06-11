#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rmparent(a,parent) a.erase(remove(a.begin(), a.end(), parent), a.end()); //see: erase - remove idiom
#define f(a) for (int i = 0; i < a; i++)
#define f2(a, b) for (int i = a; i < b; i++)

/*
essentially we need to do dp at each node in all directions, or simplified to: if the current node is black, then the answer is (the number of ways to colour the subtree rooted at this node black) * (the number of ways to colour nodes outside this subtree black). this covers all directions

state: 
	down[node] = number of ways to colour subtree nodes black
transition:
	down[parent] = (1+down[child1])*(1+down[child2])*(1+down[child3])*...
	for each child, we can let it be black or white
		if it is white, then the entire subtree rooted at that child is white. hence the 1 (nothing from that subtree)
		if it is white, then we have down[child] ways of colouring that subtree. hence down[child]

state:
	up[node] = number of ways to colour not subtree nodes black
transition:
	let us refer to children of a node's parent as the node's "brothers"
	if the parent is white: 
		there is 1 way
	if the parent if black:
		then we want the number of ways to colour the entire tree if the parent is black excluding the current subtree
		we have already defined "the number of ways to colour the entire tree if the node is black" as up[node]*down[node]
		it is basically the same idea except we cant include the current node in the parent's calculation
		so there is up[parent] * (1 + down[brother1]) * (1 + down[brother2]) * ...
		which might just look like up[parent] * down[parent] / down[node], but this cannot be done because the modulo 				might not be prime so we can't find an inverse.
		therefore, we use prefix and suffix products instead
		(product of all the down[brothers] before current node) * (product of all the down[nodes] after current node)
		note that before and after is relative to the parent's adjacency list
		at each parent, we calculate the up value of our children, then recur
*/
const int nax = 100005;
vector<int> adj[nax];
vector<ll> prefix[nax], suffix[nax];
int parent[nax], len[nax];
ll down[nax], up[nax];
ll mod;

void dfsdown(int x) {
    rmparent(adj[x],parent[x]);
    len[x] = adj[x].size(); //keep in mind we are 1 indexed
    prefix[x].resize(len[x]), suffix[x].resize(len[x]);

    ll pre = 1, suf = 1, y;
    f2(1,len[x]){
    	y = adj[x][i];
        parent[y] = x;
        dfsdown(y);
        prefix[x][i] = pre = pre * (down[y] + 1) % mod; //prefix
    }   
    for (int i = len[x]-1; i >= 1; i--) {
    	y = adj[x][i];
    	suffix[x][i] = suf = suf * (down[y] + 1) % mod; //suffix
    }
    down[x] = pre; //notice pre is the cumulative product of all children
}

void dfsup(int x) {
    f2(1,len[x]){
    	ll y = adj[x][i];
        up[y] = up[x];
        //brothers before current node
        if (i > 1) up[y] = up[y] * prefix[x][i - 1] % mod; //no prefix if at the beginning
        //brothers after current node
        if (i < len[x] - 1) up[y] = up[y] * suffix[x][i + 1] % mod; //no suffix if at the end
        up[y] += 1; //add one for when the current node (parent) is white
        dfsup(y);
    }
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n >> mod;
    f2(1,n+1) adj[i].push_back(-1); //dummy for 1 indexing
    f(n-1) {
    	int x,y;
        cin >> x >> y;
        adj[x].push_back(y), adj[y].push_back(x);
    }
    up[1] = 1;
    dfsdown(1);
    dfsup(1);
    f2(1,n+1) cout << down[i] * up[i] % mod << endl;
    return 0;
}