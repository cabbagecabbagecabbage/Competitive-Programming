import sys
n,m = map(int,input().split())
s = list(map(int,input().split()))

#from left count appearance
cileft = [-1 for i in range(1000001)]
ciright = [-1 for i in range(1000001)]

for i in range(n):
	if cileft[s[i]] == -1:
		cileft[s[i]] = i
	ciright[s[i]] = i

ml = 0
for i in range(m):
	a,b = map(int,sys.stdin.readline().split())
	if ciright[b] != -1 and cileft[a] != -1:
		ml = max(ml,ciright[b]-cileft[a]+1)
print(ml)