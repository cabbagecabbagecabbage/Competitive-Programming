j,k = map(int,input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
dp = [[-1 for i in range(1002)] for j in range(1002)]
import sys
sys.setrecursionlimit(100000)
def solve(m,n):
	if m==0 or n==0:
		return m + n
	if dp[m][n] != -1:
		return dp[m][n]
	dp[m][n] = min([solve(m-1,n)+1,solve(m,n-1)+1,solve(m-1,n-1)+(a[m-1]!=b[n-1])])
	return dp[m][n]
print(solve(j,k))