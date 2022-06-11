n = int(input())
k = int(input())
ans = n
for i in range(1,k+1):
    ans += n*10**i
print(ans)