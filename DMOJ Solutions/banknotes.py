n = int(input())
b = list(map(int,input().split()))
c = list(map(int,input().split()))
K = int(input())
dp = [0] + [100000000 for i in range(K)]

for i in range(n):
	j = 1
	while c[i] > 0:
		j = min(j,c[i])
		c[i] -= j
		for k in range(K,b[i]*j-1,-1):
			dp[k] = min(dp[k],dp[k-b[i]*j]+j)
		j *= 2
print(dp[K])