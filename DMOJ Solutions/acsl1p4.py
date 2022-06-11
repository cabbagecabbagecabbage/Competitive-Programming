x, k = map(int, input().split())

graph = [set() for i in range(x)]

for i in range(k):
	a,b,sa,sb = map(int,input().split())
	if sa > sb:
		graph[a-1].add(b-1)
	else:
		graph[b-1].add(a-1)

cyclic = [0 for i in range(x)]

def cycle(j):
	from collections import deque
	d = deque()
	d.append((j,[]))
	tempcyclic = [0 for i in range(x)]
	while d:
		#print(d)
		node, path = d.pop()
		if node in path:
			if node != path[-2]:
				for n in path[path.index(node):]:
					#print(n,"is cyclic")
					cyclic[n] = 1
					tempcyclic[n] = 1
		else:
			temp = path + [node]
			for neighbor in graph[node]:
				if not tempcyclic[neighbor]:
					d.append((neighbor, temp))
	

for j in range(x):
	if not cyclic[j]:
		checking = []
		cycle(j)

print(sum(cyclic))