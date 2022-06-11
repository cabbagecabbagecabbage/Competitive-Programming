n,m = map(int,input().split())
edges = []
adj = [set() for i in range(n+1)]
for i in range(m):
	a,b = map(int,input().split())
	adj[a].add(b)
	edges.append((a,b))
visited = []

def dfs(node):
	if node==n: return 1
	visited[node] = 1
	return sum([dfs(x) for x in adj[node] if not visited[x]])
		

for a,b in edges:
	visited = [0 for i in range(n+1)]
	adj[a].remove(b)
	if (dfs(1)): print("YES")
	else: print("NO")
	adj[a].add(b)