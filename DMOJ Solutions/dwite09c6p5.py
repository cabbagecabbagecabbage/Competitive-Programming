from queue import PriorityQueue
for _ in range(5):
	adj = {}
	n = int(input())
	visited = set(["YYZ"])
	q = PriorityQueue()
	q.put((0,"YYZ"))
	for i in range(n):
		a,b,c = input().split()
		c = int(c)
		if a not in adj:
			adj[a] = []
		adj[a].append((b,c))
	while not q.empty():
		dist, node = q.get()
		if node == "SEA":
			print(dist)
			break
		visited.add(node)
		for i,c in adj[node]:
			if i not in visited:
				q.put((dist+c,i))