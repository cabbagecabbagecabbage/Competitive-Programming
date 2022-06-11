import sys

input = sys.stdin.readline

l = [int(input().strip()) for i in range(int(input().strip()))]

prefix = [0]
for n in l:
	prefix.append(prefix[-1]+n)

for i in range(int(input().strip())):
	s,e = [int(i) for i in input().strip().split()]
	print(prefix[e+1]-prefix[s])