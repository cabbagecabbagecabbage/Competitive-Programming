for _ in range(int(input())):
 n = int(input())
 arr = [(int(i)+n)%n for i in input().split()]
 occ = [0 for i in range(n)]
 no = 0
 for i in range(n):
  if occ[(i + arr[i]) % n] != 1:
   occ[(i + arr[i]) % n] = 1
  else:
   print("NO")
   no = 1
   break
 if not no:
  print("YES")