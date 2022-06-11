conv = {"L":(-1,0),"R":(1,0),"U":(0,-1),"D":(0,1)}
h,w = map(int,input().split())
graph = [list(input()) for i in range(h)]
cam = [[0 for i in range(w)] for j in range(h)]
visitedcost = [[-1 for i in range(w)] for j in range(h)]

cameras = []
empty = []

for y in range(h):
	for x in range(w):
		if graph[y][x] == "C":
			cameras.append((x,y))
		elif graph[y][x] == ".":
			empty.append((x,y))
		elif graph[y][x] == "S":
			start = (x,y)
	
for a,b in cameras:
	cam[b][a] = 1
	for m,n in conv.values():
		nx,ny = a,b
		while 1:
			nx += m
			ny += n
			if graph[ny][nx] == "W":
				break
			if graph[ny][nx] in conv:
				continue
			cam[ny][nx] = 1

#bfs
from collections import deque
d = deque()
if not cam[start[1]][start[0]]:
	d.append(start)
	visitedcost[start[1]][start[0]] = 0
	while d:
		x,y = d.popleft()
		curcost = visitedcost[y][x]
		if graph[y][x] == "." or graph[y][x] == "S":
			for m,n in conv.values():
				nx,ny = x+m,y+n
				if graph[ny][nx] != "W" and not cam[ny][nx] and (visitedcost[ny][nx] == -1 or curcost+1<visitedcost[ny][nx]):
					visitedcost[ny][nx] = curcost+1
					d.append((nx,ny))

		else:
			dir = graph[y][x]
			nx,ny = x+conv[dir][0],y+conv[dir][1]
			if graph[ny][nx] != "W" and not cam[ny][nx] and (visitedcost[ny][nx] == -1 or curcost<visitedcost[ny][nx]):
				visitedcost[ny][nx] = curcost
				d.append((nx,ny))

for ex,ey in empty:
	print(visitedcost[ey][ex])