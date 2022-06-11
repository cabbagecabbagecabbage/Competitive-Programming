import sys
for _ in range(int(input())):
 n=int(sys.stdin.readline())
 m = 1000000000000000000000
 dic = {}
 arr = sys.stdin.readline().split()
 elements = set(arr[:])
 #combine consecutive identical
 i=0
 arr+=[-1]
 while 1:
  if i==len(arr)-1:
   break
  if arr[i+1]==arr[i]:
   del arr[i+1]
  else:
   if arr[i] in dic:
    dic[arr[i]] += 1
   else:
    dic[arr[i]] = 1
   i+=1
 del arr[-1]
 if len(arr)==1:
  print(0)
 else:
  for element in elements:
   if arr[-1] == element and arr[0] == element:
    m = min(m,dic[element]-1)
   elif arr[-1] != element and arr[0] != element:
    m = min(m,dic[element]+1)
   else:
    m = min(m,dic[element])
  print(m)