import sys
sys.setrecursionlimit(1000000)
N,C,K = map(int,input().split())
cherries = [int(i) for i in input().split()]
branches = [set() for i in range(N)]
for i in range(N-1):
	a,b,k = map(int,sys.stdin.readline().split())
	branches[a-1].add((b-1,k))

counter = 0

def dfs(n,pk):
	global counter
	neighbors = branches[n]
	if not neighbors:
		if cherries[n]>=C and pk<=K and n!=0:
			counter+=1
		#print("node",n,"cherries in subtree",cherries[n],"weight of tree",pk)
		return cherries[n],pk

	c = cherries[n]
	k = pk
	for neighbor,nk in neighbors:
		tc, tk = dfs(neighbor,nk)
		c+=tc
		k+=tk


	if c>=C and k<=K and n!=0:
		counter += 1
	#print("node",n,"cherries in subtree",c,"weight of tree",k)
	return c,k

dfs(0,0)
print(counter)