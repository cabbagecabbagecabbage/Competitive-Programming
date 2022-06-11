n = int(input())
arr = list(map(int,input().split()))

arr.sort()
l = n // 2
ans = []
for i in range(l):
	ans.append(arr[i])
	ans.append(arr[n-l+i])
if n % 2:
	ans.append(arr[l])
	
print(*ans)
for i in range(l):
	print("B",end = "")
	print("S",end = "")
if n % 2:
	print("E",end = "")
print()