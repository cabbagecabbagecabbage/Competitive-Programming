n,m = map(int,input().split())


prev = 0
diff = []
s = [int(i) for i in input().split()]+[n+1]
s.sort()
for i in s:
	diff.append(i-1-prev)
	prev = i
m = 1000000000
for i in range(len(diff)-1,-1,-1):
	if diff[i] == 0:
		del diff[i]
	else:
		m = min(m,diff[i])
ans = 0
from math import ceil
for k in diff:
	ans += ceil(k / m)
print(ans)