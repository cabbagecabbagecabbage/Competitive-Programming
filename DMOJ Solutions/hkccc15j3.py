n,m = map(int,input().split())
dirs = [(1,1),(1,-1),(-1,1),(-1,-1),(0,1),(0,-1),(1,0),(-1,0)]
graph = [[0 for i in range(n)] for j in range(n)]
for i in range(m):
	y,x = map(int,input().split())
	y-=1
	x-=1
	for xinc, yinc in dirs:
		# print(xinc,yinc)
		tx,ty = x,y
		while -1<tx<n and -1<ty<n:
			graph[ty][tx] = 1
			tx+=xinc
			ty+=yinc
# from pprint import pprint
# pprint(graph)
ans = 0
for i in range(n):
	for j in range(n):
		ans += (1-graph[i][j])
print(ans)