import sys
sys.setrecursionlimit(1000000)
n,m = map(int,input().split())
adj = [set() for i in range(n+1)]
for i in range(m):
	x,y = map(int,input().split())
	adj[x].add(y)
length = [-1 for i in range(n+1)]

ans = 0
def dfs(n):
	global ans
	if length[n] != -1:
		return length[n]

	length[n] = max([0]+[dfs(node) for node in adj[n]])+1
	if ans < length[n]:
		ans = length[n]
	return length[n]

for n in range(1,n+1):
	if length[n] == -1:
		dfs(n)
print(ans-1)