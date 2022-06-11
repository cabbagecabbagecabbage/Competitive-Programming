l = []
for i in range(int(input())):
    num = int(input())
    if num == 0:
        l.pop()
    else:
        l.append(num)
print(sum(l))