n = int(input())
x,y = map(int,input().split())
r = int(input())
diff = [0 for i in range(n+1)]
for i in range(r):
	a,b = map(int,input().split())
	diff[a] += 1
	diff[b+1] -= 1

for i in range(1,n+1):
	diff[i] += diff[i-1]
for i in range(1,n+1):
	diff[i] += diff[i-1]
print(diff[y] - diff[x-1])