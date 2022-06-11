n,m = map(int,input().split())
v = [int(i) for i in input().split()]
dp = [float('inf') for i in range(n)]
adj = [[] for i in range(n)]
for i in range(m):
	a,b = map(int,input().split())
	adj[a-1].append(b-1)
for i in range(n):
	for j in adj[i]:
		dp[j] = min(dp[i],dp[j],v[i])

ans = -99999999999999

for i in range(n):
	ans = max(ans,v[i] - dp[i])
print(ans)