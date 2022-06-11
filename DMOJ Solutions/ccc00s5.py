#trying to debug for evan
import sys
input = sys.stdin.readline
from decimal import *
getcontext().prec = 20
n = int(input())
ans = [int(i) for i in range(n)]
sheep = []
for i in range(n):
    a = Decimal(input())
    b = Decimal(input())
    sheep.append([Decimal(a),Decimal(b)])

for i in range(n):
    lower = Decimal(0)
    upper = Decimal(1000)
    x = sheep[i][0]
    y = sheep[i][1]
    for j in ans:
        if i != j:
            a = sheep[j][0]
            b = sheep[j][1]
            if x.compare(a) == 0:
                if b.compare(y) >= 0:
                    continue
                else:
                    upper = Decimal(1)
                    lower = Decimal(2)
                    break
            elif x.compare(a) == 1:
                lower = lower.max(((a**2+b**2)/2-(x**2+y**2)/2)/(a-x))
            else:
                upper = upper.min(((a**2+b**2)/2-(x**2+y**2)/2)/(a-x))
    if lower.compare(upper) == 1:
        ans.remove(i)
for j in ans:
    print(f"The sheep at ({sheep[j][0]:.2f}, {sheep[j][1]:.2f}) might be eaten.")