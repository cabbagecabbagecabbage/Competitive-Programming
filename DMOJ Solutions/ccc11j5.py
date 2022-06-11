n = int(input())
adj = [set() for i in range(n+1)] #1 indexed

for i in range(n-1):
	adj[int(input())].add(i+1)

subtrees = [[] for i in range(n+1)]

def subtree(n):
	global subtrees
	s = [n]
	for v in adj[n]:
		s+=subtree(v)
	subtrees[n] = s
	return s
subtree(n)

sets = set()
friends = [i for i in range(1,n)]
from itertools import combinations
for i in range(n):
	for c in combinations(friends,i):
		total = []
		for j in c:
			total+= subtrees[j]
		total = frozenset(total)
		sets.add(total)

print(len(sets))