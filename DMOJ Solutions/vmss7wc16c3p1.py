import sys

input = sys.stdin.readline
xc = []
yc = []
for i in range(int(input().strip())):
	x,y = [int(i) for i in input().strip().split()]
	xc.append(x)
	yc.append(y)
print((max(xc)-min(xc))*(max(yc)-min(yc)))