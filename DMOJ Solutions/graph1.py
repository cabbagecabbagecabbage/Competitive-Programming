import sys
sys.setrecursionlimit(100000)
n,m = map(int,input().split())
adj = [set() for i in range(n+1)]
visited = [0 for i in range(n+1)]
for i in range(m):
	a,b = map(int,input().split())
	adj[a].add(b)
	adj[b].add(a)
x,y = map(int,input().split())
target = y
def dfs(node):
	if (visited[node]):
		return 0
	if node==target:
		return 1
	visited[node] = 1
	s = 0
	for v in adj[node]:
		if not visited[v]:
			s |= dfs(v)
	return s

ans = 0
for i in adj[x]:
	ans += dfs(i)
visited = [0 for i in range(n+1)]
ans2 = 0
target = x
for i in adj[y]:
	ans2 += dfs(i)
print(min(min(ans,ans2),1))