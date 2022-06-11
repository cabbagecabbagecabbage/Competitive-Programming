n,m = map(int,input().split())
dist = 1000000000
cur = -1
from math import atan2,pi,radians
# from decimal import *
def calc(a,b):
	return min(abs(a-b),abs(2*pi-abs(a-b)))
m = radians(m)
for i in range(n):
	x,y = map(int,input().split())
	angle = atan2(y,x)
	distance = calc(m,angle)
	if (distance < dist):
		dist = distance
		cur = i + 1
print(cur)