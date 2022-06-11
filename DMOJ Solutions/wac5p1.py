n = int(input())
a = list(map(int,input().split()))
a.sort()

total = 0
def acorn(lis):
	global total
	total+=lis[-1]
	prev = lis[-1]
	del lis[-1]
	for i in range(len(lis)-1,-1,-1):
		if lis[i]<prev:
			prev = lis[i]
			del lis[i]
	if lis:acorn(lis)

acorn(a)
print(total)