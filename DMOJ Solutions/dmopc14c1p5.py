from collections import deque
from math import inf
r,c = map(int,input().split())
start = tuple(map(int,input().split()))
end = tuple(map(int,input().split()))
graph = [input() for i in range(r)]
dist = [[inf for i in range(c)] for j in range(r)]
alt = [tuple(map(int,input().split())) for i in range(int(input()))]

d = deque()
d.append(start)
dist[start[0]][start[1]] = 0
dirs = [[-1,0],[1,0],[0,1],[0,-1]]
while d:
	row,col = d.popleft()
	for a,b in dirs:
		na,nb = row + a, col + b
		if 0 <= na < r and 0 <= nb < c:
			if graph[na][nb] != "X" and dist[na][nb] > dist[row][col]+1:
				dist[na][nb] = dist[row][col]+1
				d.append((na,nb))
				
f = dist[end[0]][end[1]]
# print(f)
s = inf
for m,n in alt:
	s = min(s,dist[m][n])
if s == inf: s = 0
print(max(f-s,0))