#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
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
https://cp-algorithms.com/graph/second_best_mst.html#:~:text=A%20second%20best%20MST%20T,trees%20of%20the%20graph%20G.

https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)

https://www.youtube.com/watch?v=kOfa6t8WnbI
*/

struct edge {
    int s, e, w, id;
    bool operator<(const struct edge& other) { return w < other.w; }
};
typedef struct edge Edge;

const int N = 5e4 + 5, M = 1e5+5;
long long res = 0, ans = LLONG_MAX;
int n, m, a, b, w, id;
const int l = 21;
vector<Edge> edges;
int h[N],parent[N],size[N];
bool used[M];
vector<pii> adj[N];
pii toptwo[N][l];
int ancestor[N][l];


int Find(int node){
	return parent[node] == node ? node : parent[node] = Find(parent[node]);
}

bool Merge(int a, int b){
	int parenta = Find(a), parentb = Find(b);
	if (parenta == parentb) return false;
	if (size[parenta] > size[parentb]) swap(parenta,parentb);
	parent[parenta] = parentb;
	size[parentb] += size[parenta];
	return true;
}

bool mst(){
	//make MST
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    int edgecount = 0;
    for (int i = 0; i <= m - 1; i++) {
        a = edges[i].s; b = edges[i].e; w = edges[i].w; id = edges[i].id;
        if (Merge(a, b)) { 
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
            used[id] = 1;
            res += w;
            edgecount++;
        }
    }
    //make sure its valid
    return edgecount != n-1;
}



void dfs(int u, int par, int d) {
    h[u] = 1 + h[par];
    ancestor[u][0] = par; //2^0 = 1
    toptwo[u][0] = {d, -1};
    for (auto v : adj[u])
        if (v.first != par)
        	dfs(v.first, u, v.second);
}

pii getTop2(pii a, pii b) {
	//take 2 pairs of ints and combines into a pair of {biggest,secondbiggest}
    int secondbiggest = -1, biggest = -1;
    for (int c : {a.first, a.second, b.first, b.second}) {
        if (c > biggest) secondbiggest = biggest, biggest = c;
        else if (c < biggest) secondbiggest = max(secondbiggest,c);
    }
    return {biggest, secondbiggest};
}

void precompute(){
	//precompute
    mem(ancestor,-1);
    dfs(1, 0, 0);
    for (int i = 1; i <= l - 1; i++) {
        for (int j = 1; j <= n; ++j) {
            if (ancestor[j][i - 1] != -1) {
                int v = ancestor[j][i - 1];
                ancestor[j][i] = ancestor[v][i - 1];
                toptwo[j][i] = getTop2(toptwo[j][i - 1], toptwo[v][i - 1]);
            }
        }
    }
}

pii lca(int u, int v) {
    pair<int, int> ans = {-1, -1};
    // walk to the same depth (while updating ans)
    if (h[u] < h[v]) swap(u, v);
    for (int i = l - 1; i >= 0; i--) {
	        if ((h[u] - h[v]) & (1 << i)) {
            ans = getTop2(ans, toptwo[u][i]);
            u = ancestor[u][i];
        }
    }
    if (u == v) return ans; //if one is the ancestor of the other we're done
	//start jumping / binary searching
    for (int i = l - 1; i >= 0; i--) {
        if (ancestor[u][i] != -1 && ancestor[v][i] != -1){
        	if (ancestor[u][i] != ancestor[v][i]) { //dont overshoot
	            ans = getTop2(ans, getTop2(toptwo[u][i], toptwo[v][i]));
	            u = ancestor[u][i];
	            v = ancestor[v][i];
	        }
        }
    }
    ans = getTop2(ans, getTop2(toptwo[u][0], toptwo[v][0]));
    return ans;
}

void tryedges(){
	//try every edge
    for (int i = 0; i <= m - 1; i++) {
        long long newcost = res + edges[i].w;
        //if the edge is not already used
        if (!used[edges[i].id]) {
        	int big, nextbig;
            tie(big,nextbig) = lca(edges[i].s, edges[i].e); //find 2 biggest edges in cycle
            
            //greatest edge that is not equal to the edge we're trying to put in
            if (big != edges[i].w) newcost -= big, ans = min(ans,newcost);

            //if the first edge was our edge but a second greatest edge exists
            else if (nextbig != -1) newcost -= nextbig, ans = min(ans,newcost);
        }
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    in2(n,m);
    for (int i = 1; i <= m; i++) {
        in3(a,b,w); // 1-indexed
        edges.push_back({a, b, w, i - 1});
    }
    if (mst()){
    	out(-1);
    	return 0;
    }
    
    precompute();
    
    tryedges();
    
    out((ans == LLONG_MAX ? -1 : ans));
    return 0;
}














//trailing lines ftw