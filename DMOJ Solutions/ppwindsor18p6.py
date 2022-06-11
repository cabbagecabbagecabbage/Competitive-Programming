from collections import deque
from sys import stdin
m = int(input())
n = int(input())
move = [[0,1] , [0,-1], [1,0], [-1,0]]
grid = []
visited = [[0 for j in range(m)] for k in range(n)]
for i in range(n):
	row = list(stdin.readline())
	for a in range(m):
		if row[a] == '1':
			start = (i, a)
			visited[i][a] = 1
	grid.append(row)
d = deque()
d.append(start)
reachable = []
while d:
		x,y = d.popleft()
		if grid[x][y] != 'O':
			reachable.append(int(grid[x][y]))
		for a,b in move:
			na,nb = x+a,y+b
			if 0<=na<n and 0<=nb<m and grid[na][nb] != '#' and not visited[na][nb]:
				d.append((na,nb))
				visited[na][nb] = 1

reachable.sort()
print(*reachable)