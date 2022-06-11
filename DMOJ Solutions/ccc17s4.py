import sys
n,m,d = map(int,input().split()) #cities, pipes, enhance
edges = []
for i in range(m):
	a,b,c = map(int,sys.stdin.readline().split())
	if i<n-1:
		edges.append((c,0,a,b))
	else:
		edges.append((c,1,a,b))
# 0 active, 1 inactive bc sorting
edges.sort()

#kruskals, union find

def find(vertex):
	#returns the parent of the vertex
	global parent
	if parent[vertex] == vertex:
		return vertex
	parent[vertex] = find(parent[vertex])
	return parent[vertex]

def union(a,b):
	#make 2 sets into one set (no path compression? idk)
	global parent
	pa = find(a)
	pb = find(b)
	if pa == pb:
		return False
	parent[pa] = pb
	return True

def main():
	#initialize all vertices as their own subset
	global parent
	parent = [i for i in range(n+1)]
	edgecount = 0
	days = 0
	wl = 0
	maxe = 0
	#go thru the edges
	for i in range(m):
		c,s,a,b = edges[i]
		if edgecount == n-1:
			break
		if union(a,b):
			wl = c #edge weight is always non decreasing
			maxe = not s
			edgecount += 1
			if s:
				days += 1

	# "only edges with weight equal to that of the heaviest edge will be replaced" because we must use the enhancer on the heaviest edge to achieve the minimum cost
	# take each originally active edge. if, after enhancing, the price goes down to 0

	if not maxe:
		parent = [i for i in range(n+1)]
		for c,s,a,b in edges:
			if find(a) != find(b):
				if c<wl or (c==wl and not s): # "if the edge's weight is less than wl or was in the original MST and has a weight equal to wl" either cant be replaced, or already active in the beginning
					union(a,b)
				elif not s and c<=d: # "if the weight of the edge is ≤D and is also an old edge" if it can be replaced (weight >= wl, not in mst, originally active) and can be enhanced down to 0
					return days-1
	return days

print(main())