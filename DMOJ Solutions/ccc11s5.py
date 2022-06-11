k = int(input())
lights = [int(input()) for i in range(k)]
groups = []
forming = 0
for i in range(k):
	if forming:
		if lights[i]:
			groups[-1][1] += 1
		else:
			forming = 0
	else:
		if lights[i]:
			forming = 1
			groups.append([i,i+1])

from math import inf
l = len(groups)
dp = [0 for i in range(l+1)]
for i in range(l-1,-1,-1):
	dp[i] = inf
	j = i
	n = 0
	left = groups[i][0]
	right = groups[j][1]
	while j<l and groups[j][1] - left <= 7:
		right = groups[j][1]
		n += right - groups[j][0]
		span = max(4, right-left)
		switchneeded = span-n

		if span == 6 and lights[left+2] and lights[left+3]:
			switchneeded = inf
		elif span == 7 and lights[left+3]:
			switchneeded = inf

		dp[i] = min(dp[i],switchneeded+dp[j+1])

		j += 1
		
print(dp[0])