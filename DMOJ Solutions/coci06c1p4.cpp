#include <bits/stdc++.h>
using namespace std;

/*
for each cell, calc the min days they get flooded by taking each puddle and bfs

then shortest path by bfs on s
*/

int grid[55][55],minflood[55][55],dist[55][55],r,c;
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

void bfs(int i, int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	minflood[i][j] = 0;
	while (!q.empty()){
		int a,b; tie(a,b) = q.front(); q.pop();
		for (int k = 0; k < 4; ++k){
			int ni = a + y[k], nj = b + x[k];
			if (grid[ni][nj] > 0 and minflood[ni][nj] > minflood[a][b] + 1){
				minflood[ni][nj] = minflood[a][b] + 1;
				q.push({ni,nj});
			}
		}
	}
}

int32_t main(){
	memset(minflood, 0x3f, sizeof minflood);
	cin >> r >> c;
	int sx,sy,ex,ey;
	for (int i = 1; i <= r; ++i){
		string s; cin >> s;
		s = " " + s;
		for (int j = 1; j <= c; ++j){
			if (s[j] == '*') grid[i][j] = 2;
			if (s[j] == '.') grid[i][j] = 1;
			if (s[j] == 'S'){
				grid[i][j] = 1;
				sy = i, sx = j;
			}
			if (s[j] == 'D'){
				grid[i][j] = -1;
				ey = i, ex = j;
			}
		}
	}
	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			if (grid[i][j] == 2){
				bfs(i,j);
			}
		}
	}
	// for (int i = 1; i <= r; ++i){
		// for (int j = 1; j <= c; ++j){
			// cout << minflood[i][j] << " ";
		// }
		// cout << "\n";
	// }
	queue<pair<int,int>> q;
	q.push({sy,sx});
	memset(dist,0x3f,sizeof dist);
	dist[sy][sx] = 0;
	while (!q.empty()){
		int a,b; tie(a,b) = q.front(); q.pop();
		for (int k = 0; k < 4; ++k){
			int ni = a + y[k], nj = b + x[k];
			if (grid[ni][nj] and minflood[ni][nj] > dist[a][b] + 1 and dist[ni][nj] > dist[a][b] + 1){
				dist[ni][nj] = dist[a][b] + 1;
				q.push({ni,nj});
			}
		}
	}
	if (dist[ey][ex] == 0x3f3f3f3f){
		cout << "KAKTUS\n";
	}
	else cout << dist[ey][ex] << "\n";
	return 0;
}