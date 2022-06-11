from collections import deque
import sys
input = sys.stdin.readline
for _ in range(int(input().strip())):
	x,y = map(int,input().strip().split())

	graph = ["X"*(x+2)]

	for i in range(y):
		row = "X"+input().strip()+"X"
		if "C" in row:
			start = (i+1,row.find("C")) #(y,x)
		graph.append(row)
	graph.append("X"*(x+2))
	#[print(*i) for i in graph]

	#bfs
	d = deque()
	d.append(start)
	worth = 0
	visited = [[0 for i in range(x+1)] for j in range(y+1)]

	while d:
		y,x = d.popleft()
		if graph[y][x] == "W":
			if visited[y][x]<60:
				worth = visited[y][x]
			break
		if graph[y-1][x] != "X" and not visited[y-1][x]:
			d.append((y-1,x))

			visited[y-1][x]=visited[y][x]+1
		if graph[y+1][x] != "X" and not visited[y+1][x]:
			d.append((y+1,x))

			visited[y+1][x]=visited[y][x]+1
		if graph[y][x-1] != "X" and not visited[y][x-1]:
			d.append((y,x-1))
			visited[y][x-1]=visited[y][x]+1

		if graph[y][x+1] != "X" and not visited[y][x+1]:
			d.append((y,x+1))
			visited[y][x+1]=visited[y][x]+1

	if worth:
		print(worth)
	else:
		print("#notworth")