from queue import Queue
dirs = [[1,0],[-1,0],[0,1],[0,-1]]

def bfs(start,end,r,c,grid):
	q = Queue()
	q.put(start)
	visited = [[0 for i in range(11)] for j in range(11)]
	while not q.empty():
		y,x = q.get()
		if (y,x) == end:
			return visited[y][x]
		for a,b in dirs:
			na,nb = y+a,x+b
			if not visited[na][nb] and 0 <= na < r and 0 <= nb < c and grid[na][nb] != "#":
				visited[na][nb] = visited[y][x] + 1
				q.put((na,nb))
		
def main():
	r,col = map(int,input().split())
	grid = []

	for i in range(r):
		row = list(input())
		try:
			a = (i,row.index("A"))
		except:
			pass
		try:
			b = (i,row.index("B"))
		except:
			pass
		try:
			c = (i,row.index("C"))
		except:
			pass
		grid.append(row)
	d = 0
	d += bfs(a,b,r,col,grid)
	d += bfs(b,c,r,col,grid)
	d += bfs(c,a,r,col,grid)
	print(d)
for i in range(5):
	main()