def fair(n):
 num = n
 while n:
  t = n%10
  n //= 10
  if t and num % t:
   return 0
 return 1
 
for i in range(int(input())):
 num = int(input())
 while 1:
  if fair(num):
   print(num)
   break
  num+=1