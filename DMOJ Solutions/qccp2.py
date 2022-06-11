import sys
n = int(sys.stdin.readline())
x = list(map(int,sys.stdin.readline().split()))
y = list(map(int,sys.stdin.readline().split()))
maxx = max(x)
minx = min(x)
maxy = max(y)
miny = min(y)

maxcol = [max(maxy, x[i]) for i in range(n)]
maxrow = [max(maxx, y[i]) for i in range(n)]
mincol = [max(miny, x[i]) for i in range(n)]
minrow = [max(minx, y[i]) for i in range(n)]


for i in range(int(sys.stdin.readline())):
	q,pos = map(int,sys.stdin.readline().split())
	pos -= 1
	if q == 1:
		print(maxcol[pos])
	elif q == 2:
		print(mincol[pos])
	elif q == 3:
		print(maxrow[pos])
	else:
		print(minrow[pos])