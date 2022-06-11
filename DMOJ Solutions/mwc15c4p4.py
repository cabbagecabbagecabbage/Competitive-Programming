#debugging for club member
import sys
input=sys.stdin.readline
from collections import deque
n=int(input())

g=[[]for i in range(n+1)]
for i in range(1,n+1):
    x,y=map(int,input().split())
    g[x].append(y)
start,end=map(int,input().split())
v=[False for i in range(n+1)]
v[start]=True
q=deque()
q.append(start)

while q:
    c=q.pop()
    if c == end:
        print('Tangled')
        break
    for vertex in g[c]:
        if v[vertex] == False:
            v[vertex]=True
            q.append(vertex)            
if v[end] == False or start>n or end>n:
    print('Not Tangled')