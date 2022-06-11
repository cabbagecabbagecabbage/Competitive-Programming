for _ in range(int(input())):
 n = int(input())
 arr = [3,1,4,2]
 if n <= 3:
  print(-1)
 else:
  for i in range(5,n+1):
   if i % 2:
    arr.append(i)
   else:
    arr.insert(0,i)
  print(*arr)