import sys
from math import inf
n,m = map(int,sys.stdin.readline().split())
graph = [[inf for i in range(n+1)] for j in range(n+1)]

for i in range(m):
	a,b,c = map(int,sys.stdin.readline().split())
	graph[a][b] = graph[b][a] = min(graph[a][b], c)

dist = [inf for i in range(n+1)]
dist[1] = 0

from queue import PriorityQueue
q = PriorityQueue()
q.put((0,1))

while not q.empty():
	cost,node = q.get()
	for i in range(1,n+1):
		newcost = cost+graph[node][i]
		if newcost < dist[i]:
			dist[i] = newcost
			q.put((newcost,i))

for i in range(1,n+1):
	print(dist[i] if dist[i] < inf else -1)