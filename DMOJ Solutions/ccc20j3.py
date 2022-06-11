n = int(input())
x = []
y = []
for i in range(n):
    a,b = map(int,input().split(","))
    x.append(a)
    y.append(b)
left = min(x) - 1
bottom = min(y) - 1
right = max(x) + 1
top = max(y) + 1

print(f'{left},{bottom}')
print(f'{right},{top}')