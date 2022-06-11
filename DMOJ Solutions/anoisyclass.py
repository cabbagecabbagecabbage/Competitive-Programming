from collections import deque
n = int(input())
m = int(input())
graph = [set() for i in range(n+1)]
for i in range(m):
	a,b = map(int,input().split())
	graph[a].add(b)

def dfs(start):
	visited = [0 for i in range(n+1)]
	d = deque()
	d.append(start)
	while d:
		node = d.pop()
		visited[node] = 1
		for i in graph[node]:
			if visited[i]:
				return 1
			d.append(i)
	return 0
    
print("N" if sum([dfs(i) for i in range(n)]) else "Y")