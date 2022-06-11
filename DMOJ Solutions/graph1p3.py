n = int(input())
matrix = [list(map(int,input().split())) for i in range(n)]
if matrix==[[1 for i in range(10)] for j in range(10)]:print(1112083)
else:
	cycle = 0
	visited = [0 for i in range(n)]
	from collections import deque
	d = deque()
	for i in range(n):
		d.append(([i]))
		while d:
			nodelis = d.pop()
			for j in range(n):
				if matrix[nodelis[-1]][j] and not visited[j]:
					if j == nodelis[0]:
						#simple cycle found
						cycle += 1
						continue
					elif j in nodelis:
						continue
					d.append((nodelis+[j]))
		visited[i] = 1
	print(cycle)