#testing purposes
import sys,time
from collections import defaultdict

t1=time.time()
M = int(input())
N = int(input())

Map = {}
D = defaultdict(set)
for x in range(1,M+1):
    line = input().split()
    #1,2,3,4,5
    for y in range(1,N+1):
        num = int(line[y-1])
        if (x,y) == (1,1):
            start = num
        D[x*y].add(num)

if time.time()-t1 >1:
    print(time.time()-t1)
    sys.exit()
if (M,N) == (1,1):
    print("yes")
    sys.exit()


Found = set()
Current = [start]
finish = M*N
while len(Current)>0:
    current = Current.pop()
    if current == finish:
        print("yes")
        sys.exit()
    if current in Found:
        continue
    Found.add(current)
    Current.extend(D[current])


print("no")