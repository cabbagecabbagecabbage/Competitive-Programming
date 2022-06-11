n,q = map(int,input().split())
freq = [0 for i in range(100002)]
for x in input().split():
	freq[int(x)] += 1
import sys
for i in range(q):
	x,y = map(int,sys.stdin.readline().split())
	if x== 1:
		if y % 2:
			freq[y // 2] += freq[y]
			freq[y // 2 + 1] += freq[y]
			freq[y] = 0
		else:
			freq[y // 2] += freq[y]*2
			freq[y] = 0
	else:
		print(freq[y])