n = int(input())

arr = [int(input()) for i in range(n)]
ans = 1
biggerthanone = 0
neg = []
for i in range(n):
	if arr[i] > 1:
		ans *= arr[i]
		biggerthanone = 1
	elif arr[i] < 0:
		neg.append(arr[i])

if (len(neg))%2:
	neg.sort()
	neg.pop()
for n in neg:
	ans *= n
	biggerthanone = 1
if biggerthanone:
	print(ans)
else:
	print(max(arr))