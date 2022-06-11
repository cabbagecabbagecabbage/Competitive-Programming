#debugging for someone
import sys
input=sys.stdin.readline
import heapq
n,m,b,q=map(int,input().split())
g=[[]for i in range(n+1)]

for i in range(m):
  x,y,z=map(int,input().split())
  g[x].append((y,z))
  g[y].append((x,z))

dist=[10000000000 for i in range(n+1)]

def dijkstra(g,n,b):
  visit=[False for _ in range(n+1)]
  dist[b]=0
  heap=[]
  heapq.heappush(heap, (0,b))
  while heap:
    weight,node=heapq.heappop(heap)

    if dist[node] != weight: continue
    for newnode,newweight in g[node]:
      if visit[newnode]: continue
      newDist = dist[node]+newweight
      if newDist<dist[newnode]:
        dist[newnode]=newDist
        heapq.heappush(heap, (newDist,newnode))

dijkstra(g,n,b)

for i in range(q):
  start=int(input())
  print(-1 if dist[start] == 10000000000 else dist[start])