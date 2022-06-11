r,c = map(int,input().split())

graph=[[0 for i in range(c+1)] for j in range(r+1)]

for i in range(int(input())):
	a,b = map(int,input().split())
	graph[a][b] = -1

graph[0][1] = 1



for y in range(1,r+1):
	for x in range(1,c+1):

		if graph[y][x] > -1:
			if graph[y][x-1]>-1 and graph[y-1][x]>-1:
				graph[y][x] = graph[y][x-1]+graph[y-1][x]
			elif graph[y][x-1] == -1 and graph[y-1][x] > -1:
				graph[y][x] = graph[y-1][x]
			elif graph[y][x-1] > -1 and graph[y-1][x] == -1:
				graph[y][x] = graph[y][x-1]

print(graph[r][c])
#[print(*i) for i in graph]