n,m,a,b = map(int,input().split())

graph = [set() for i in range(n+1)]

for i in range(m):
	x,y = map(int,input().split())
	graph[x].add(y)
	graph[y].add(x)

from collections import deque

visited = [0 for i in range(n+1)]
def main():
	d = deque()
	d.append(a)
	while d:
		node = d.pop()
		visited[node] = 1
		if node == b:
			return "GO SHAHIR!"
		for v in graph[node]:
			if not visited[v]:
				d.append(v)

	return "NO SHAHIR!"
print(main())