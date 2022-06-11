import sys
n = int(sys.stdin.readline())
t = int(sys.stdin.readline())
graph = [[0 for i in range(n+1)] for j in range(n+1)]
for i in range(t):
	a,b,c = map(int,sys.stdin.readline().split())
	graph[a][b] = c
	graph[b][a] = c


from math import inf
dist = [inf for i in range(n+1)]

from queue import PriorityQueue
d = PriorityQueue()

for k in range(int(sys.stdin.readline())):
	a,b = map(int,sys.stdin.readline().split())
	dist[a] = min(dist[a],b)
	d.put((b,a))

dest = int(sys.stdin.readline())

while not d.empty():
	curcost,city = d.get()

	if city == dest:
		break

	adj = graph[city]
	for i in range(1,n+1):
		cost = adj[i]
		totalcost = cost+curcost
		if cost and totalcost < dist[i]:
			dist[i] = totalcost
			d.put((totalcost,i))
print(dist[dest])