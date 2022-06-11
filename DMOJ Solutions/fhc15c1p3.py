from collections import deque
for t in range(int(input())):
	myscore, opscore = map(int,input().split("-"))

	#stress free
	#dp[myscore][opscore]
	#we want myscore > opscore, always

	dp = [[0 for i in range(opscore+1)] for j in range(myscore+1)]

	for y in range(myscore+1):
		dp[y][0] = 1

	for y in range(2,myscore+1):
		for x in range(1,min(y,opscore+1)):
			dp[y][x] = dp[y-1][x] + dp[y][x-1]

	print(f'Case #{t+1}:',dp[myscore][opscore]%1000000007,end = " ")

	dp = [[0 for i in range(opscore+1)] for j in range(myscore+1)]

	for x in range(opscore+1):
		dp[0][x] = 1

	for y in range(1,myscore+1):
		for x in range(min(y,opscore),opscore+1):
			dp[y][x] = dp[y-1][x] + dp[y][x-1]

	print(dp[myscore][opscore]%1000000007)
	#print(f"Case #{i}: {stressfree(myscore,opscore)}")