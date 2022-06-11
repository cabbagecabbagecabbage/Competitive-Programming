n,m = map(int,input().split())
edges = []
adj = [set() for i in range(n+1)]
for i in range(m):
	a,b = map(int,input().split())
	adj[a].add(b)
	adj[b].add(a)
	edges.append((a,b))
ans = [1000000000000,1000000000000,1000000000000,1000000000000]
for i in range(1,n+1):
	for a,b in edges:
		if a in adj[i] and b in adj[i]:
			t = sorted((i,a,b))
			ans = min(ans,t)

if ans == [1000000000000,1000000000000,1000000000000,1000000000000]:
	for i in range(m):
		for j in range(i):
			if len(set([edges[i][0],edges[i][1],edges[j][0],edges[j][1]])) == 4:
				t = sorted((edges[i][0],edges[i][1],edges[j][0],edges[j][1]))
				ans = min(ans,t)

if ans == [1000000000000,1000000000000,1000000000000,1000000000000]:
	print(-1)
else:
	ans.sort()
	print(len(ans))
	print(*ans)