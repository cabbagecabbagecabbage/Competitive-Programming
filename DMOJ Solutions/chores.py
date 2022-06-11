n = int(input())
arr = [[int(i) for i in input().split()] for j in range(n)]
arr.sort(key = lambda x: x[0])
ans = 0
mod = 1000000000 + 7
prev = 0
for num,occ in arr:
	ans = (ans + (prev * occ)%mod) % mod
	ans = (ans + ((occ * (occ+1)) // 2 % mod) * num % mod)% mod
	prev += occ*num % mod
	prev %= mod
print(ans)