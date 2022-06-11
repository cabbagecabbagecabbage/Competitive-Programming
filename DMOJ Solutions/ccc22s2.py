import sys
input = sys.stdin.readline
yes = set()
no = set()

ans = 0

x = int(input())
for i in range(x):
	a,b = input().split()
	yes.add((min(a,b),max(a,b)))
	ans += 1

y = int(input())
for i in range(y):
	a,b = input().split()
	no.add((min(a,b),max(a,b)))

g = int(input())
for i in range(g):
	a,b,c = sorted(input().split())
	if (a,b) in yes:
		ans -= 1
	if (a,c) in yes:
		ans -= 1
	if (b,c) in yes:
		ans -= 1
	if (a,b) in no:
		ans += 1
	if (a,c) in no:
		ans += 1
	if (b,c) in no:
		ans += 1
print(ans)