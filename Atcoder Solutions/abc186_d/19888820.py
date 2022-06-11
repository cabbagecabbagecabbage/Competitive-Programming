n = int(input())
arr = sorted([int(i) for i in input().split()])
ans = 0
for i in range(n):
	ans += arr[i]*i
	ans -= arr[i]*(n-(i+1))
print(ans)