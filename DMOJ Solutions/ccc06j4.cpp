#include <bits/stdc++.h>
using namespace std;

int vis[10];
vector<int> adj[10];
stack<int> s;
int col = 0;

bool dfs(int u){
	//return true if it finds a cycle
	vis[u] = col;
	for (int v: adj[u]){
		if (vis[v] == vis[u]){
			//in the same iteration we visited v already: there is a cycle
			return true;
		}
		if (!vis[v]){
			if (dfs(v)){
				return true;
			}
		}
		
	}
	//after reaching all the nodes it can reach, add it to the stack
	s.push(u);
	return false;
}

int32_t main(){
	while (true){
		int a,b; cin >> a >> b;
		if (a == 0) break;
		adj[a].emplace_back(b);
	}
	adj[1].emplace_back(7);
	adj[1].emplace_back(4);
	adj[2].emplace_back(1);
	adj[3].emplace_back(4);
	adj[3].emplace_back(5);
	
	for (int i = 7; i >= 1; --i){
		if (!vis[i]){
			++col;
			if (dfs(i)){
				//cycle is found
				cout << "Cannot complete these tasks. Going to bed." << "\n";
				return 0;
			}
		}
	}
	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
	
	return 0;
}