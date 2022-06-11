a,b = 100,100
for i in range(int(input())):
    n,m = map(int,input().split())
    if n==m:
        continue
    if n > m:
        b -= n
    else:
        a -= m
print(a)
print(b)