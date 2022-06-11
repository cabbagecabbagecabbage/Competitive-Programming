s = [int(input()) for i in range(int(input()))]
print(min(sum(s)-max(s),sum(s)//2))