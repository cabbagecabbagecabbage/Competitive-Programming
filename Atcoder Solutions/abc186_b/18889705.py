h,w = map(int,input().split())
graph = [list(map(int,input().split())) for i in range(h)]
m = 100000000000
s = 0
for y in range(h):
	for x in range(w):
		m = min(m,graph[y][x])
		s += graph[y][x]

print(s-m*h*w)
