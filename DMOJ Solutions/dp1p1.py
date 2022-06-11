import sys
input = sys.stdin.readline
l=int(input().strip())
i = 0
o = 0
for x in range(l):
	temp = max(i,o)
	i = o + int(input().strip())
	o = temp
print(max(i,o))