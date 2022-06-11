n = int(input())
pos = [tuple(map(int,input().split())) for i in range(n)]
# from decimal import *
# getcontext().prec = 12
pos.sort()
speeds = []
for i in range(n-1):
	dist = abs(pos[i][1]-pos[i+1][1])
	t = pos[i+1][0]-pos[i][0]
	speed = dist/t
	speeds.append(speed)
print(max(speeds))