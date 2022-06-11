n = int(input())
ans = 0
cur = 0
for i in input().split():
	i = int(i)
	if i % 2:
		cur = 0
	else:
		cur += i
	ans = max(ans, cur)
print(ans)