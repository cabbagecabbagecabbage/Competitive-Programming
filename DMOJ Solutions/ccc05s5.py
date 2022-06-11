import sys
def u(i):
	while i<=n:
		tree[i] += 1
		i += (i & -i)
def s(i):
	t = 0
	while i>0:
		t += tree[i]
		i -= (i & -i)
	return t
n = int(input())	
tree = [0 for i in range(n+1)]
rank = [0 for i in range(n)]
scores = [(int(sys.stdin.readline()),i) for i in range(n)]
scores.sort()
ans = 0
for i in range(n):
	rank[scores[i][1]] = n-i
for i in range(n):
	u(rank[i])
	crank = s(rank[i])
	ans += crank
print(f'{round(ans/n,2):.2f}')