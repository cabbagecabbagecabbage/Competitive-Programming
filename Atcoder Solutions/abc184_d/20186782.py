x,y,z = map(int,input().split())
dp = [[[-1 for i in range(101)] for j in range(101)] for k in range(101)]
def solve(a,b,c):
	if a == 100 or b == 100 or c == 100:
		return 0
	if dp[a][b][c] != -1:
		return dp[a][b][c]
	s = a+b+c
	dp[a][b][c] = (solve(a+1,b,c) + 1)*(a/s) + (solve(a,b+1,c) + 1)*(b/s) + (solve(a,b,c+1) + 1)*(c/s)
	return dp[a][b][c]
print(solve(x,y,z))