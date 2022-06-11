# CCC '16 S3 - Phonomenal Reviews
# implementation based on editorial written by FatalEagle https://dmoj.ca/problem/ccc16s3/editorial
# essentially the problem is broken down into 2 main parts: pruning the tree so that only the vertices we must visit remain, then computing the minimal time by finding the diameter (see explanation in editorial)


# take input
n,m = map(int,input().split())

ispho = [0 for i in range(n)]
for i in map(int,input().split()):
	ispho[i] = 1

adj = [set() for i in range(n)]
for i in range(n-1):
	a,b = map(int,input().split())
	adj[a].add(b)
	adj[b].add(a)

# prune tree with bfs, starting from the leaves of the tree until we reach a restaurant
# notice that if a node only has 1 connection, then it must be a leaf. we add that to our queue
from collections import deque # a normal queue also works
d = deque()

for i in range(n):
	if len(adj[i]) == 1 and not ispho[i]:
		d.append(i)

while d:
	node = d.popleft()
	for neighbor in adj[node]:
		adj[neighbor].remove(node)
		if len(adj[neighbor]) == 1:
			if not ispho[neighbor]:
				d.append(neighbor)

#calculate the diameter using 2 traversals finding the farthest node

random = ispho.index(1)
dist = [-1 for i in range(n)]
dist[random] = 0
d.append(random)

while d:
	node = d.popleft()
	for neighbor in adj[node]:
			if dist[neighbor] == -1:
				dist[neighbor] = dist[node]+1
				d.append(neighbor)
farthest = dist.index(max(dist))

#repeat process again

dist = [-1 for i in range(n)]
dist[farthest] = 0
d.append(farthest)

while d:
	node = d.popleft()
	for neighbor in adj[node]:
		if dist[neighbor] == -1:
			dist[neighbor] = dist[node]+1
			d.append(neighbor)

diameter = max(dist)

print(2*(n-1-dist.count(-1))-diameter)