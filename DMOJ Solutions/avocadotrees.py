import sys
n,q,h = map(int,sys.stdin.readline().split())
psa = [0]
for i in range(n):
	a,b = map(int,sys.stdin.readline().split())
	psa.append(psa[-1])
	if a <= h:
		psa[-1] += b
m = 0
for i in range(q):
	l,r = map(int,input().split())
	m = max(m,psa[r]-psa[l-1])
print(m)