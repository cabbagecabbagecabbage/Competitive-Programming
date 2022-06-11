#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
double n,x[maxn],y[maxn];
bool visited[maxn];

double dist(int u, int v){
	//returns the square of the distance between any two nodes
	double dx = x[u] - x[v], dy = y[u] - y[v];
	return dx*dx + dy*dy;
}

void dfs(int u, double r){
	//depth-first search to traverse the graph
	visited[u] = true;
	for (int v = 1; v <= n; ++v){
		//only visited unvisited nodes that are close enough
		if (!visited[v] and dist(u,v) <= 4*r*r) dfs(v,r);
	}
}

bool valid(double radius){
	dfs(1,radius); //start the traversal anywhere
	bool ans = true;
	for (int i = 1; i <= n; ++i){
		if (!visited[i]) ans = false; //if any node is unreached, the radius is invalid
		visited[i] = false; //set unvisited for next call
	}
	return ans;
}

int32_t main(){
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> x[i] >> y[i];
	}
	//binary search for the minimum radius
	double lo = 0, hi = 1e9;
	while (hi - lo > 1e-7){
		double mid = (lo + hi) / 2;
		if (valid(mid)) hi = mid;
		else lo = mid;
	}
	cout << fixed << setprecision(7) << lo << "\n";
	return 0;
}