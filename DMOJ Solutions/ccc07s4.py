n = int(input())
adj = [set() for i in range(n+1)]
while 1:
	a,b = map(int,input().split())
	if (a,b) == (0,0):
		break
	else:
		adj[a].add(b)

paths = [0 for i in range(n+1)]
def sumpaths(v):
	if v == n:
		return 1
	s = 0	
	for node in adj[v]:
		if paths[node]:
			s += paths[node]
		else:
			s += sumpaths(node)
	paths[v] = s
	return s
print(sumpaths(1))