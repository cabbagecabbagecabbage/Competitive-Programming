from collections import deque
import sys
dirs = [(0,1),(0,-1),(1,0),(-1,0)]
for _ in range(int(input())):
	r = int(sys.stdin.readline())
	c = int(sys.stdin.readline())
	graph = [list(sys.stdin.readline().strip()) for i in range(r)]
	cost = [[-1 for i in range(c)] for j in range(r)]

	if graph[-1][-1] == "*":
		print(-1)
		continue

	r-=1
	c-=1
	d = deque()
	d.append((0,0))
	cost[0][0] = 1

	while d:
		x,y = d.popleft()

		curcost = cost[y][x]
		if x == c and y == r:
			break
		curdir = []
		if graph[y][x] == "+":
			curdir = dirs
		elif graph[y][x] == "-":
			curdir = dirs[2:]
		elif graph[y][x] == "|":
			curdir = dirs[:2]

		for a,b in curdir:
			nx,ny = x+a, y+b
			if 0<=nx<=c and 0<=ny<=r and cost[ny][nx] == -1:
				d.append((nx,ny))
				cost[ny][nx] = curcost+1

	print(cost[-1][-1])