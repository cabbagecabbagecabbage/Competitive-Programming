import sys
n,m,q,c = map(int,input().split())
adj = [[] for i in range(n+1)]
dist = [100000000 for i in range(n+1)]
from collections import deque
d = deque()
d.append(c)
dist[c] = 0
for i in range(m):
	u,v = map(int,sys.stdin.readline().split())
	adj[u].append(v)
	adj[v].append(u)
while d:
	node = d.popleft()
	for v in adj[node]:
		if dist[node] + 1 < dist[v]:
			dist[v] = dist[node] + 1
			d.append(v)
for i in range(q):
	a,b = map(int,sys.stdin.readline().split())
	if (dist[a] == 100000000 or dist[b] == 100000000): print("This is a scam!")
	else: print(dist[a] + dist[b])