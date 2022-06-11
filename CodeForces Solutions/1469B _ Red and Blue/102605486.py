for _ in range(int(input())):
 n = int(input())
 amax = 0
 asum = 0
 for i in input().split():
  asum += int(i)
  amax = max(amax,asum)
 
 m = int(input())
 bmax = 0
 bsum = 0
 for i in input().split():
  bsum += int(i)
  bmax = max(bmax,bsum)
 print(bmax+amax)