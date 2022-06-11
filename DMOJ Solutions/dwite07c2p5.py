def dfs(node, prev):
	global counter, entrytime, adj, visited
	visited[node] = 1
	entry[node] = low[node] = entrytime
	entrytime += 1
	for v in adj[node]:
		if v!=prev:
			if visited[v]:
				low[node] = min(low[node],entry[v])
			else:
				dfs(v, node)
				low[node] = min(low[node],low[v])
				if entry[node] < low[v]:
					counter += 1

for _ in range(5):
	n,m = int(input()), int(input())
	adj = [set() for i in range(n+1)]
	for i in range(m):
		a,b = map(int,input().split())
		adj[a].add(b)
		adj[b].add(a)
	
	counter = 0
	entrytime = 0
	visited = [0 for i in range(n+1)]
	entry = [0 for i in range(n+1)]
	low = [0 for i in range(n+1)]
	dfs(1,-1)
	print(counter)