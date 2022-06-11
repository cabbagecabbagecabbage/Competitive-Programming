# You will be given a description of the pens, along with the placement of animals, 
# and you are to figure out what the smallest cost is to move all the animals into the same area

#in other words remove edges (at a minimum cost) so that the pens all connect to each other, or the outside
#take in input so that the pens are the vertices, not the corners. the edges are now between pens or outside

##### taking in input #####
from math import inf
m = int(input())
edges = {} # key value pairs of edges and the pens they connect (first element is cost)
costs = [[inf for i in range(m+1)] for i in range(m+1)] #adjacency matrix, storing edgecosts. cost[m] being the outside
outside = {}
for i in range(m): # for every pen
	e,*p = map(int,input().split()) # num of edges, {the corners} + {their edge cost}
	for j in range(e): # for every edge
		edge = tuple(sorted((p[j],p[(j+1)%(e)]))) # pair it up

		if edge in edges: # if the edge has already been stored before
			edges[edge].append(i) # just add this pen to it
		else:
			edges[edge] = [p[j+e],i] # otherwise map the key to the value which is [cost,current pen]

#make the adjacency matrix of the dual graph
for key in edges:
	value = edges[key]
	if len(value) == 2:
		cost,n = value
		costs[-1][n] = min(cost,costs[-1][n])
		costs[n][-1] = min(cost,costs[n][-1])
	else:
		cost,a,b = value
		costs[a][b] = min(cost,costs[a][b])
		costs[b][a] = min(cost,costs[b][a])

costs2 = [costs[i][:-1] for i in range(m)] #without the outside

from queue import PriorityQueue
def prims(numofvertices,matrix):
	totalcost = 0
	visited = [0 for i in range(numofvertices)]
	keys = PriorityQueue()
	keys.put((0,0))
	while not keys.empty():
		cost,node = keys.get()
		if visited[node] == 0:
			totalcost += cost
			visited[node] = 1
			neighbors = matrix[node]
			for i in range(numofvertices):
				if neighbors[i] != inf and not visited[i]:
					keys.put((neighbors[i],i))
	if 0 not in visited:
		return totalcost
	else:
		return 999999999999
print(min(prims(m+1,costs),prims(m,costs2)))