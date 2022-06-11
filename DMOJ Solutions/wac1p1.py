import math
for x in range(int(input())):
	k=int(input())
	n=math.ceil((1+((1+8*k)**0.5))/2)
	if n*(n-1) >= 2*k >= (n-1)*(n-2):
		print(n)
	else:
		print(n+1)