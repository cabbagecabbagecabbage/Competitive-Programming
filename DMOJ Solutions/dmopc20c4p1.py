from math import ceil,floor
for _ in range(int(input())):
	n,s = map(int,input().split())
	total = n * (n + 1) // 2
	diff = total - s
	dif2 = diff / 2
	right = floor(dif2 + 1)
	left = ceil(dif2 - 1)
	#inclusive
	right = n - right + 1
	left = left - 1 + 1
	print(min(right,left))