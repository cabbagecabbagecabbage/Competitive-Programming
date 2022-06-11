import sys
def main():
	n,m = map(int,input().split())
	graph = [set() for i in range(n+1)]
	for i in range(m):
		a,b = map(int,sys.stdin.readline().split())
		graph[a].add(b)
	p,q = map(int,input().split())


	#bfs
	from collections import deque
	d = deque()
	d.append(p)
	visited = [0 for i in range(n+1)]
	while d:
		node = d.pop()
		visited[node] = 1
		if node == q:
			return "yes"
		for neighbor in graph[node]:
			if not visited[neighbor]:
				d.append(neighbor)


	d = deque()
	d.append(q)
	visited = [0 for i in range(n+1)]
	while d:
		node = d.pop()
		visited[node] = 1
		if node == p:
			return "no"
		for neighbor in graph[node]:
			if not visited[neighbor]:
				d.append(neighbor)

	
	return "unknown"

print(main())