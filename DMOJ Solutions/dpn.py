from math import inf
n = int(input())
arr = list(map(int,input().split()))
prefix = [0]
for k in arr:
	prefix.append(prefix[-1]+k)

memo = [[-1 for i in range(n)] for j in range(n)]
def solve(l,r):
	if l==r:
		return arr[l]
	if memo[l][r] != -1:
		return memo[l][r]
	res = inf
	for i in range(l,r):
		res = min(res,prefix[r+1]-prefix[l]+solve(l,i)+solve(i+1,r))
	memo[l][r] = res
	return res

print(solve(0,n-1)-prefix[n])