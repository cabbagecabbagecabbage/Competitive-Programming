n = int(input())
arr = [int(i) for i in input().split()]
s = sum(arr)
if s%2 or max(arr) > s - max(arr):
 print("NO")
else:
 print("YES")