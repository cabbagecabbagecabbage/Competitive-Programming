from decimal import *
getcontext().prec = 20
n,x = [Decimal(j) for j in input().split()]

for i in range(int(n)):
	v,p = [Decimal(j) for j in input().split()]
	x -= v * p / 100
	if x < 0:
		print(i+1)
		break
if (x >= 0):
	print(-1)