import sys
c,r,d = map(int,sys.stdin.readline().split())
adj = [[] for i in range(c+1)]
for i in range(r):
	a,b,w = map(int,sys.stdin.readline().split())
	# make weights negative is my 200iq move
	adj[a].append((-w,b))
	adj[b].append((-w,a))

# find the maximum spanning tree
from queue import PriorityQueue
q=PriorityQueue()
q.put((-1000000,1))

visited = [-1 for i in range(c+1)]
visited[0] = -1000000 #we are doing 1 indexed
while not q.empty():
	w,n = q.get()
	if visited[n] == -1:
		visited[n] = w
		for nw,nn in adj[n]:
			if visited[nn] == -1:
				q.put((nw,nn))

maxd = -1000000	
for i in range(d):
	des = visited[int(sys.stdin.readline())]
	if des>maxd:
		maxd = des
print(-maxd)