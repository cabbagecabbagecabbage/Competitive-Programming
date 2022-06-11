n,m = map(int,input().split())
original = []
for i in range(n):
    original.append((int(input())*244002641)%(2**32))
original.sort()
print(sum(original[-m:]))