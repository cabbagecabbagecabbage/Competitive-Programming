#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n,m,k; cin >> n >> m >> k;
	vector<vector<int>> colour(n,vector<int>(m)),visited(n,vector<int>(m));
	priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>> q;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> colour[i][j];
			if (colour[i][j] != 0){
				visited[i][j] = true;
				q.emplace(0,colour[i][j],i,j);
			}
		}
	}
	vector<int> dx = {0,0,1,-1};
	vector<int> dy = {-1,1,0,0};
	while (!q.empty()){
		auto [dist,col,y,x] = q.top(); q.pop();
		if (dist + 1 > k) continue;
		for (int i = 0; i < 4; ++i){
			int ny = y + dy[i], nx = x + dx[i];
			if (0 <= ny and ny < n and 0 <= nx and nx < m){
				if (!visited[ny][nx]){
					visited[ny][nx] = true;
					colour[ny][nx] = col;
					q.emplace(dist+1,col,ny,nx);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout << colour[i][j] << " \n"[j == m-1];
		}
	}
	return 0;
}