n = int(input())
riceballs = list(map(int,input().split()))

dp = [[-1 for i in range(n+1)] for i in range(n+1)]
prefix = [0]
for i in range(1,n+1):
	prefix.append(riceballs[i-1]+prefix[i-1])

def sumrange(a,b):
	return prefix[b]-prefix[a]

maxans = 0
def fill(i,j):
	global maxans
	
	if dp[i][j]>-1:
		return dp[i][j]
	if i+1 >= j:
		dp[i][j] = 1
		maxans = max(maxans,sumrange(i,j))
		return 1
	k = i+1
	l = j-1
	while k <= l:
		leftsum = sumrange(i,k)
		rightsum = sumrange(l,j)
		if leftsum == rightsum:
			if fill(i,k) and fill(k,l) and fill(l,j):
				dp[i][j] = 1
				maxans = max(maxans,sumrange(i,j))
				return 1
			k+=1
			l-=1
		elif leftsum < rightsum:
			k+=1
		elif leftsum > rightsum:
			l-=1
	dp[i][j] = 0
	return 0

for i in range(n):
	for j in range(i+1,n+1):

		fill(i,j)

print(maxans)