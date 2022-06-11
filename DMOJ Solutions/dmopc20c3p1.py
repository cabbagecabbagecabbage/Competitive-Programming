int(input())
arr = input().split()
if len(arr) != len(set(arr)):
	print("NO")
else:
	print("YES")