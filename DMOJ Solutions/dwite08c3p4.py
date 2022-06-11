from math import inf
dp = []
coins = []
def solve(n):
	if n < 0:
		return inf
	if n == 0:
		return 0
	if dp[n] != -1:
		return dp[n]
	ans = inf
	for c in coins:
		ans = min(ans,solve(n-c) + 1)
	dp[n] = ans
	return ans

for i in range(5):
	coins = []	
	m = int(input())
	n = int(input())
	dp = [-1 for i in range(m+1)]
	for j in range(n):
		coins.append(int(input()))
	print(solve(m))