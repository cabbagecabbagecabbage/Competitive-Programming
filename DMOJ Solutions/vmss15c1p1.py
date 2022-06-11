a = int(input())
l = []
for i in range(1,int(a**(1/2))+1):
	if a%i == 0:
		l.append([i,a//i])
small = a*2
for m in l:
	if sum(m) < small:
		small = sum(m)
print(small*2)