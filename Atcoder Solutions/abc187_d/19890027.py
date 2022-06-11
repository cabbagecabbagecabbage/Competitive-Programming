n = int(input())
arr = []
other = 0
for i in range(n):
	a,b = map(int,input().split())
	arr.append((2*a+b,a,b))
	other += a
arr.sort(reverse = 1)
cur = 0
for i in range(n):
	x,a,b = arr[i]
	cur += a+b
	other -= a
	if cur > other:
		print(i+1)
		break