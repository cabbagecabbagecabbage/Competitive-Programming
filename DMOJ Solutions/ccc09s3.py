graph = [{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}]

graph+=[set() for i in range(60)]

from collections import deque
def f(x):
	count = set()
	for v in graph[x]:
		for v2 in graph[v]:
			if v2 not in graph[x] and v2 != x:
				count.add(v2)

	return len(count)

def s(x,y):
	d = deque()
	visited = [-1 for i in range(len(graph))]
	d.append(x)
	visited[x] = 0
	while d:
		n = d.popleft()
		if n == y:
			return visited[n]
		for v in graph[n]:
			if visited[v] == -1:
				d.append(v)
				visited[v] = visited[n]+1
	return "Not connected"

while True:
	cmd = input()
	if cmd == "q":
		break
	elif cmd == "i":
		x,y = int(input()),int(input())
		graph[x].add(y)
		graph[y].add(x)

	elif cmd == "d":
		x,y = int(input()),int(input())
		graph[x].discard(y)
		graph[y].discard(x)

	elif cmd == "n":
		x = int(input())
		print(len(graph[x]))

	elif cmd == "f":
		x = int(input())
		print(f(x))

	elif cmd == "s":
		x = int(input())
		y = int(input())
		print(s(x,y))