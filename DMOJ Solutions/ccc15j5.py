a = int(input())
b = int(input())

from math import ceil,inf

import functools

@functools.lru_cache(maxsize=None)
def picklast(n,k,cap):
	if (k==1 and n<=cap):
		return 1
	sol = 0
	for i in range(ceil(n/k),min(n-k+2,cap+1)):
		sol+=picklast(n-i,k-1,i)
	return sol

print(picklast(a,b,inf))