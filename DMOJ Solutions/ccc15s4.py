k, n, m = map(int,input().split())
roads = [[] for i in range(n+1)]
for i in range(m):
	a,b,t,h = map(int,input().split())
	roads[a].append((b,t,h))
	roads[b].append((a,t,h))

start, finish = [int(i) for i in input().split()]

from math import inf

checking = [0 for i in range(n+1)]

dist = [[inf for i in range(k+1)] for i in range(n+1)]

for i in range(k):
	dist[start][i] = 0
checking[start] = True

from collections import deque
pq = deque()
pq.append(start)

while pq:

	node = pq.popleft()
	checking[node] = 0

	for road in roads[node]: #for each road

		b,t,h = road #next,time,hulldamage = road
		#print(b,t,h)
		for j in range(k-h+1): #for each damage that does not go over k (maximum)
			path = dist[node][j] + t #length of total path with the road = distance to currentnode [damage] + time of the road
			if path<dist[b][j+h]: #if that length is shorter than the path at the next node with the same damage
				dist[b][j+h] = path #replace with the shorter path
				if not checking[b]: #if the node isnt being checked already
					checking[b] = 1
					pq.append(b) #put it in and checking = 1

m = dist[finish][k-1]

print(m if m < inf else -1)