dp = [[[0 for i in range(3)] for j in range(4)] for k in range(100005)]

digit = [0 for i in range(100005)]
	
mod = 1000000000 + 7;

n = 0;

for c in input():
	digit[n] = ord(c) - 48;
	n += 1

dp[0][0][0] = 1;
for i in range(n):
	curdig = digit[i];
	
	if (curdig == 1): mul = 0
	else: mul = 1;
	dp[i+1][0][0] += (dp[i][0][0]*mul % mod)
	dp[i+1][0][0] %= mod
	if (curdig == 1): mul = 1
	else: mul = max(curdig - 1, 0)
	dp[i+1][0][1] += (dp[i][0][0]*mul % mod)
	dp[i+1][0][1] %= mod
	if (curdig == 1):
		dp[i+1][1][0] += dp[i][0][0]
		dp[i+1][1][0] %= mod
	if (curdig > 1): 
		dp[i+1][1][1] += dp[i][0][0]
		dp[i+1][1][1] %= mod
	dp[i+1][0][1] += (dp[i][0][1]*9 % mod)
	dp[i+1][0][1] %= mod
	dp[i+1][1][1] += dp[i][0][1]
	dp[i+1][1][1] %= mod
	

	if (curdig != 0):
		dp[i+1][1][0] += (dp[i][1][0])
		dp[i+1][1][0] %= mod
	if (curdig > 0):
		dp[i+1][1][1] += (dp[i][1][0]*(curdig-1) % mod)
		dp[i+1][1][1] %= mod
	dp[i+1][1][1] += dp[i][1][1]*9 % mod
	dp[i+1][1][1] %= mod
	if (curdig != 0):
		dp[i+1][2][1] += dp[i][1][0]
		dp[i+1][2][1] %= mod
	if (curdig == 0):
		dp[i+1][2][0] += dp[i][1][0]
		dp[i+1][2][0] %= mod
	dp[i+1][2][1] += dp[i][1][1]
	dp[i+1][2][1] %= mod


	if (curdig != 0):
		dp[i+1][2][0] += (dp[i][2][0])
		dp[i+1][2][0] %= mod
	if (curdig > 1): 
		dp[i+1][2][1] += (dp[i][2][0]*(curdig-1) % mod)
		dp[i+1][2][1] %= mod
	dp[i+1][2][1] += (dp[i][2][1]*9 % mod)
	dp[i+1][2][1] %= mod

print((dp[n][2][0] + dp[n][2][1]) % mod)