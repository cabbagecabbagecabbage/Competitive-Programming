#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define qq cout << "\n";
typedef vector<int> vi;
typedef pair<int,int> pii;

long long arr[200005],comingin[200005],backward[200005];
vi adj[200005], rev[200005];
int visited[200005] = {};
stack<int> sorted,revsorted;
int n;

void topsort(int v){
	visited[v] = 1;
	for (int x:adj[v]){
		if (!visited[x]){
			topsort(x);
		}
	}
	sorted.push(v);
}
void revsort(int v){
	visited[v] = 1;
	for (int x:rev[v]){
		if (!visited[x]){
			revsort(x);
		}
	}
	revsorted.push(v);
}

void fupdate(int v){
	visited[v] = 1;
	for (int x:adj[v]){
		comingin[x] += comingin[v];
		fupdate(x);
	}
}

void bupdate(int v){
	visited[v] = 1;
	for (int x:rev[v]){
		backward[x] += backward[v];
		bupdate(x);
	}
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	vector<pair<int,int>> edges;
    cin >> n;
    int a,u,v;
    f(n){
    	cin >> a;
    	arr[i] = comingin[i] = backward[i] = a;
    }
    f(n-1){
    	cin >> u >> v;
    	u--;v--;
    	adj[u].push_back(v);
    	rev[v].push_back(u);
    	edges.push_back(make_pair(u,v));
    }
    f(n){
    	if (!visited[i]) topsort(i);
    }

    memset(visited,0,sizeof(visited));
    while(!sorted.empty()){
    	// if (!visited[sorted.top()]) fupdate(sorted.top());
    	// cout << sorted.top()+1 << " ";
    	for (int x:adj[sorted.top()]){
    		comingin[x] += comingin[sorted.top()];
    	}
    	sorted.pop();
    }
    // qq
    memset(visited,0,sizeof(visited));
    f(n){
    	if (!visited[i]) revsort(i);
    }
 
    memset(visited,0,sizeof(visited));
    while(!revsorted.empty()){
    	// if (!visited[revsorted.top()]) bupdate(revsorted.top());
    	// cout << revsorted.top()+1 << " ";
    	for (int x:rev[revsorted.top()]){
    		backward[x] += backward[revsorted.top()];
    	}
    	revsorted.pop();
    }
	// qq
    long long ans = 0;
    f(n-1){
    	ans = max(ans,(comingin[edges[i].second]-comingin[edges[i].first])*(backward[edges[i].first]-backward[edges[i].second]));
    }
    // cout << ans;qq
    f(n){
    	ans += arr[i]*(backward[i]-1);
    }
    cout << ans;qq

	return 0;
}