from math import ceil
for i in range(int(input())):
 n,k = map(int,input().split())
 a = (n+k)%k
 if a == 0: t = n
 else: t = n+k - a
 print(ceil(t/n))