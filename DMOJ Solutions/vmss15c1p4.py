t,n,m,g = map(int,input().split()) #kilometers he can drive, buildings he can visit, roads he can drive on, number of food basics
foodbasics = [int(input()) for i in range(g)]
roads = {i:[] for i in range(n)}
for i in range(m):
	a,b,l = map(int,input().split())
	roads[a].append((b,l))

#note: assume that each food basics has roads going out from it

queue = [(0,0)] #building, length
visited = [0 for i in range(n)]
total = set()
while queue:
	node,length = queue[-1]
	del queue[-1]

	visited[node] = 1
	if node in foodbasics:
		#print(node)
		total.add(node)

	for nextnode,l in roads[node]:
		if length+l <= t and (not visited[nextnode]):
			queue.append((nextnode,length+l))
	
print(len(total))