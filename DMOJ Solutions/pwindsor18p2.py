from math import *
n = int(input())
a = [[int(z) for z in input().split(" ")] for i in range(n)]
b = []
for x in a:
	b.append(hypot(x[0],x[1]))
print(" ".join([str(i) for i in a[b.index(max(b))]]))