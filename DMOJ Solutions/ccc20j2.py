p = int(input())
n = int(input())
r = int(input())
days = 0
nex = n
count = n
while count<=p:
		count += nex*r
		nex = nex*r
		days += 1

print(days)