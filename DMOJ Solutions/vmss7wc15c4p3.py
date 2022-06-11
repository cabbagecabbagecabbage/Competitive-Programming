n, m = map(int,input().split())
start = 0
end = n-1
adj = [set() for i in range(n)]
for i in range(m):
	a,b,c = map(int,input().split())
	adj[a].add((b,c))
	adj[b].add((a,c))

# single source both ways

from math import inf
dist = [inf for i in range(n)]
dist[0] = 0

from queue import PriorityQueue
q = PriorityQueue()
q.put((0,0))
while not q.empty():
	cost,node = q.get()
	if dist[node] != cost:
		continue
	for b,c in adj[node]:
		if dist[b] > dist[node] + c:
			dist[b] = dist[node] + c
			q.put((dist[node] + c, b))


dist2 = [inf for i in range(n)]
dist2[end] = 0
q.put((0,end))
while not q.empty():
	cost,node = q.get()
	if dist2[node] != cost:
		continue
	for b,c in adj[node]:
		if dist2[b] > dist2[node] + c:
			dist2[b] = dist2[node] + c
			q.put((dist2[node] + c, b))

m = 0
for i in range(1,n-1):
	m = max(m,dist[i]+dist2[i])
print(m)