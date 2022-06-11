n,k = map(int,input().split())
m = sorted([int(i) for i in input().split()])[::-1]
print(sum(m[:k]))